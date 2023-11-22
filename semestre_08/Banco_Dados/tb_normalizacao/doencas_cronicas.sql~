-- Create the function
CREATE OR REPLACE FUNCTION normalizando_dados()
RETURNS SETOF view_descryp AS
$$
BEGIN

    DROP TABLE IF EXISTS municipio CASCADE;
    DROP TABLE IF EXISTS prontuario CASCADE;
    DROP TABLE IF EXISTS pessoa;
    DROP TABLE IF EXISTS tabela_principal;

    CREATE TABLE tabela_principal (
        dt_obito date,
        dt_nascimento date,
        nu_idade int,
        sg_sexo varchar(10),
        tp_raca_cor char(20),
        tp_escolaridade varchar(30),
        co_municipio_ibge_residencia char(50),
        co_municipio_ibge_ocorrencia char(50),
        co_cid_causa_basica varchar(10),
        desc_cid_causa_basica varchar(50),
        capitulo_cid_causa_basica varchar(50),
        categoria_cid_causa_basica varchar(50)
    );

    COPY tabela_principal FROM '/dados/tb_normalizacao/dados_cronicas_ses_2023.csv' DELIMITER ';' CSV HEADER;

    CREATE TABLE municipio (
        municipio_id serial primary key,
        nome varchar(30)
    );

    WITH municipios_dist AS (
        SELECT co_municipio_ibge_residencia AS co_residencia FROM tabela_principal
        UNION
        SELECT co_municipio_ibge_ocorrencia AS co_ocorrencia FROM tabela_principal
    )
    INSERT INTO municipio (nome)
    SELECT DISTINCT co_residencia FROM municipios_dist;

    CREATE TABLE prontuario (
        prontuario_id serial primary key,
        co_cid_causa_basica varchar(100),
        desc_cid_causa_basica varchar(100),
        capitulo_cid_causa_basica varchar(100),
        categoria_cid_causa_basica varchar(100)
    );

    INSERT INTO prontuario (co_cid_causa_basica, desc_cid_causa_basica, capitulo_cid_causa_basica, categoria_cid_causa_basica)
    SELECT DISTINCT co_cid_causa_basica, desc_cid_causa_basica, capitulo_cid_causa_basica, categoria_cid_causa_basica FROM tabela_principal;

    CREATE TABLE pessoa (
        pessoa_id serial primary key,
        dt_obito date,
        dt_nascimento date,
        sexo char(100),
        raca char(100),
        residencia int,
        prontuario_p int
    );

    INSERT INTO pessoa (dt_obito, dt_nascimento, sexo, raca, residencia, prontuario_p)
    SELECT tp.dt_obito, tp.dt_nascimento, tp.sg_sexo, tp.tp_raca_cor, m.municipio_id, pr.prontuario_id FROM tabela_principal tp
    JOIN municipio m ON m.nome = tp.co_municipio_ibge_residencia
    JOIN prontuario pr ON pr.co_cid_causa_basica = tp.co_cid_causa_basica;

    ALTER TABLE pessoa
    ADD CONSTRAINT fk_residencia FOREIGN KEY (residencia) REFERENCES municipio(municipio_id);

    ALTER TABLE pessoa
    ADD CONSTRAINT fk_prontuario FOREIGN KEY (prontuario_p) REFERENCES prontuario(prontuario_id);

    CREATE EXTENSION IF NOT EXISTS pgcrypto;

    ALTER TABLE prontuario
    ADD COLUMN crypt_cau BYTEA,
    ADD COLUMN crypt_cap BYTEA,
    ADD COLUMN crypt_cat BYTEA;

    UPDATE prontuario
    SET crypt_cau = pgp_sym_encrypt(co_cid_causa_basica::TEXT, '1245'),
        crypt_cap = pgp_sym_encrypt(capitulo_cid_causa_basica::TEXT, '1245'),
        crypt_cat = pgp_sym_encrypt(categoria_cid_causa_basica::TEXT, '1245');

    ALTER TABLE prontuario
    DROP COLUMN co_cid_causa_basica,
    DROP COLUMN capitulo_cid_causa_basica,
    DROP COLUMN categoria_cid_causa_basica;

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
        m.nome AS residencia,
        pgp_sym_decrypt(pr.crypt_cau, '1245') AS desc_cid_causa_basica,
        pgp_sym_decrypt(pr.crypt_cap, '1245') AS desc_cid_capitulo_basica,
        pgp_sym_decrypt(pr.crypt_cat, '1245') AS categoria_cid_causa_basica
    FROM
        pessoa p
    JOIN
        municipio m ON p.residencia = m.municipio_id
    JOIN
        prontuario pr ON p.prontuario_p = pr.prontuario_id;

    RETURN QUERY SELECT * FROM view_descryp;
END;
$$
LANGUAGE plpgsql;

select * from view_descryp;

