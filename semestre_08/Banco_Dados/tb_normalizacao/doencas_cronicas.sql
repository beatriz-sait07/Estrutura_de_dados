DROP FUNCTION IF EXISTS normalizacao() CASCADE;

CREATE OR REPLACE FUNCTION normalizacao() 
RETURNS TABLE 
(
        pessoa_id INT,
        dt_obito DATE,
        dt_nascimento DATE,
        tempo_de_vida INTERVAL,
        crypt_sexo TEXT,
        crypt_rc TEXT,
        escolaridade VARCHAR,
        nome TEXT,
        crypt_cau TEXT,
        crypt_cap TEXT,
        crypt_cat TEXT,
        desc_cid VARCHAR
    ) 
AS $$
BEGIN
    DROP VIEW IF EXISTS view_descryp CASCADE;
    DROP TABLE IF EXISTS cids CASCADE;
    DROP TABLE IF EXISTS municipio CASCADE;
    DROP TABLE IF EXISTS prontuario CASCADE;
    DROP TABLE IF EXISTS pessoa;
    DROP TABLE IF EXISTS tabela_principal;

    CREATE TABLE tabela_principal (
        dt_obito date,
        dt_nascimento date,
        nu_idade int,
        sg_sexo char(10),
        tp_raca_cor char(20),
        tp_escolaridade varchar(30),
        co_municipio_ibge_residencia varchar(50),
        co_municipio_ibge_ocorrencia varchar(50),
        co_cid_causa_basica varchar(10),
        desc_cid_causa_basica varchar(50),
        capitulo_cid_causa_basica varchar(50),
        categoria_cid_causa_basica varchar(50)
    );

    COPY tabela_principal FROM '/dados/tb_normalizacao/dados_cronicas_ses_2023.csv' DELIMITER ';' CSV HEADER;

    CREATE TABLE municipio (
        municipio_id serial primary key,
        nome text
    );

    WITH municipios_dist AS (
        SELECT co_municipio_ibge_residencia AS co_residencia FROM tabela_principal
        UNION
        SELECT co_municipio_ibge_ocorrencia AS co_ocorrencia FROM tabela_principal
    )
    INSERT INTO municipio (nome)
    SELECT DISTINCT co_residencia FROM municipios_dist;

        CREATE TABLE cids (
        id serial primary key,
        co_cid varchar(100),
        desc_cid varchar(100),
        capitulo_cid varchar(100),
        categoria_cid varchar(100)
    );

    INSERT INTO cids (co_cid, desc_cid, capitulo_cid, categoria_cid)
    SELECT DISTINCT co_cid_causa_basica, desc_cid_causa_basica, capitulo_cid_causa_basica, categoria_cid_causa_basica FROM tabela_principal;

    CREATE TABLE prontuario (
        prontuario_id serial primary key,
        cid_id int REFERENCES cids(id)
    );

    INSERT INTO prontuario (cid_id)
    SELECT id FROM cids;



    CREATE TABLE pessoa (
        pessoa_id serial primary key,
        dt_obito date,
        dt_nascimento date,
        sexo char(100),
        raca char(100),
        escolaridade varchar(30),
        residencia int REFERENCES municipio(municipio_id),
        prontuario_p int REFERENCES prontuario(prontuario_id)
    );

    INSERT INTO pessoa (dt_obito, dt_nascimento, sexo, raca, escolaridade, residencia, prontuario_p)
    SELECT tp.dt_obito, tp.dt_nascimento, tp.sg_sexo, tp.tp_raca_cor, tp.tp_escolaridade, m.municipio_id, pr.prontuario_id FROM tabela_principal tp
    JOIN municipio m ON m.nome = tp.co_municipio_ibge_residencia
    JOIN cids cd ON cd.co_cid = tp.co_cid_causa_basica
    JOIN prontuario pr ON pr.cid_id = cd.id;

    ALTER TABLE pessoa
    ADD CONSTRAINT fk_residencia FOREIGN KEY (residencia) REFERENCES municipio(municipio_id);

    ALTER TABLE pessoa
    ADD CONSTRAINT fk_prontuario FOREIGN KEY (prontuario_p) REFERENCES prontuario(prontuario_id);

    CREATE EXTENSION IF NOT EXISTS pgcrypto;

    ALTER TABLE cids
    ADD COLUMN crypt_cau BYTEA,
    ADD COLUMN crypt_cap BYTEA,
    ADD COLUMN crypt_cat BYTEA;

    UPDATE cids
    SET crypt_cau = pgp_sym_encrypt(co_cid::TEXT, '1245'),
        crypt_cap = pgp_sym_encrypt(capitulo_cid::TEXT, '1245'),
        crypt_cat = pgp_sym_encrypt(categoria_cid::TEXT, '1245');

    ALTER TABLE cids
    DROP COLUMN co_cid,
    DROP COLUMN capitulo_cid,
    DROP COLUMN categoria_cid;

    ALTER TABLE pessoa
    ADD COLUMN crypt_sexo BYTEA,
    ADD COLUMN crypt_rc BYTEA;

    UPDATE pessoa
    SET crypt_sexo = pgp_sym_encrypt(sexo::TEXT, '1245'),
        crypt_rc = pgp_sym_encrypt(raca::TEXT, '1245');

    ALTER TABLE pessoa
    DROP COLUMN sexo,
    DROP COLUMN raca;

CREATE OR REPLACE VIEW view_descryp AS
    SELECT 
        p.pessoa_id,
        p.dt_obito,
        p.dt_nascimento,
        age(p.dt_obito, p.dt_nascimento) AS tempo_de_vida,
        pgp_sym_decrypt(p.crypt_sexo, '1245') AS sexo,
        pgp_sym_decrypt(p.crypt_rc, '1245') AS raca,
        p.escolaridade,
        m.nome AS residencia,
        pgp_sym_decrypt(cd.crypt_cau, '1245') AS causa_cid,
        pgp_sym_decrypt(cd.crypt_cap, '1245') AS capitulo_cid,
        pgp_sym_decrypt(cd.crypt_cat, '1245') AS categoria_cid,
        cd.desc_cid AS descricao_cid
    FROM
        pessoa p
    JOIN
        municipio m ON p.residencia = m.municipio_id
    JOIN
        cids cd ON p.prontuario_p = cd.id
    JOIN
        prontuario pr ON p.prontuario_p = pr.prontuario_id;

RETURN QUERY SELECT * FROM view_descryp;


END; $$ LANGUAGE plpgsql;
