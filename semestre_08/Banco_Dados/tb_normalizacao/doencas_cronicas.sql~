\set quiet on --usado para nÃ£o mostrar o comando na tela

--excluindo tabelas caso elas existam
drop table if exists prontuario;
drop table if exists municipio;
drop table if exists pessoa;
drop table if exists tabela_principal;

--criando a tabela principal
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

--copiando os dados para a tabela principal
copy tabela_principal from
    '/dados/tb_normalizacao/dados_cronicas_ses_2023.csv' DELIMITER ';' CSV HEADER ;

--criando a tabela de residencias
create table municipio (
    cidade_id serial primary key,
    co_municipio_ibge_residencia char(50),
    co_municipio_ibge_ocorrencia char(50)
);

--inserindo dados na tabela de residencias
insert into municipio (co_municipio_ibge_residencia, co_municipio_ibge_ocorrencia)
select co_municipio_ibge_residencia, co_municipio_ibge_ocorrencia
from tabela_principal;

create table prontuario (
    prontuario_id serial primary key,
    dt_obito date,
    co_cid_causa_basica varchar(10),
    desc_cid_causa_basica varchar(50)
);

--inserindo dados na tabela de prontuario
insert into prontuario (dt_obito, co_cid_causa_basica, desc_cid_causa_basica)
select dt_obito, co_cid_causa_basica, desc_cid_causa_basica
from tabela_principal;

--criando a tabela de doenças crônicas (pessoa)
create table pessoa (
    pessoa_id serial primary key,
    dt_nascimento date,
    sg_sexo varchar(10),
    tp_raca_cor char(20),
    tp_escolaridade varchar(30),
    residencia int,
    prontuario_p int
);

--inserindo dados na tabela pessoa
insert into pessoa (dt_nascimento, sg_sexo, tp_raca_cor, tp_escolaridade)
select dt_nascimento, sg_sexo, tp_raca_cor, tp_escolaridade
from tabela_principal;

-- Adicionando chaves estrangeiras na tabela pessoa
alter table pessoa
add constraint residencia_fk foreign key (residencia) references municipio (cidade_id);

alter table pessoa
add constraint prontuario_fk foreign key (prontuario_p) references prontuario (prontuario_id);

\set quiet off
