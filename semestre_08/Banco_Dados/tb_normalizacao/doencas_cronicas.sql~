\set quiet on -- usado para não mostrar o comando na tela (so funciona se tiver maiusculo -.-)

-- excluindo tabelas caso elas existam
drop table if exists municipio cascade;
drop table if exists prontuario cascade;
drop table if exists pessoa;
drop table if exists tabela_principal;

-- criando a tabela principal
create table tabela_principal (
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

-- copiando os dados para a tabela principal
copy tabela_principal from '/dados/tb_normalizacao/dados_cronicas_ses_2023.csv' DELIMITER ';' CSV HEADER;

-- criando a tabela de residências
create table municipio (
    municipio_id serial primary key,
    nome varchar(30)
);

-- inserindo dados na tabela de residências
with municipios_dist as (
    select co_municipio_ibge_residencia as co_residencia from tabela_principal
    union
    select co_municipio_ibge_ocorrencia as co_ocorrencia from tabela_principal
)
insert into municipio (nome)
select distinct co_residencia from municipios_dist;

-- criando a tabela de prontuário
create table prontuario (
    prontuario_id serial primary key,
    co_cid_causa_basica varchar(100),
    desc_cid_causa_basica varchar(100),
    capitulo_cid_causa_basica varchar(100),
    categoria_cid_causa_basica varchar(100)
);

-- inserindo dados na tabela de prontuário
insert into prontuario (co_cid_causa_basica, desc_cid_causa_basica, capitulo_cid_causa_basica, categoria_cid_causa_basica)
select distinct co_cid_causa_basica, desc_cid_causa_basica, capitulo_cid_causa_basica, categoria_cid_causa_basica from tabela_principal;

-- criando a tabela de pessoas
create table pessoa (
    pessoa_id serial primary key,
    dt_obito date,
    dt_nascimento date,
    sexo char(100),
    raca char(100),
    residencia int,
    prontuario_p int
);

-- inserindo dados na tabela de pessoas
insert into pessoa (dt_obito, dt_nascimento, sexo, raca, residencia, prontuario_p)
select tp.dt_obito, tp.dt_nascimento, tp.sg_sexo, tp.tp_raca_cor, m.municipio_id, pr.prontuario_id from tabela_principal tp
join municipio m on m.nome = tp.co_municipio_ibge_residencia
join prontuario pr on pr.co_cid_causa_basica = tp.co_cid_causa_basica;

create extension if not exists pgcrypto;

--criptografando a tabela de prontuario
alter table prontuario
add column crypt_cau BYTEA,
add column crypt_cap BYTEA,
add column crypt_cat BYTEA;

update prontuario
SET crypt_cau = pgp_sym_encrypt(co_cid_causa_basica::text, '1245'),
    crypt_cap = pgp_sym_encrypt(capitulo_cid_causa_basica::text, '1245'),
    crypt_cat = pgp_sym_encrypt(categoria_cid_causa_basica::text, '1245');

alter table prontuario
add column dcrypt_cau TEXT,
add column dcrypt_cap TEXT,
add column dcrypt_cat TEXT;


update prontuario
SET dcrypt_cau = pgp_sym_decrypt(crypt_cau, '1245'),
    dcrypt_cap = pgp_sym_decrypt(crypt_cap, '1245'),
    dcrypt_cat = pgp_sym_decrypt(crypt_cat, '1245');

\set quiet off
