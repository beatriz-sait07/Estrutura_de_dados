\set quiet on --usado para não mostrar o comando na tela

--excluindo tabelas caso elas existam
DROP TABLE IF EXISTS tabela_principal;

--criando a tabela principal
create table tabela_principal (
    dt_obito date ,
    dt_nascimento date ,
    nu_idade int ,
    sg_sexo varchar(20) ,
    tp_raca_cor char(20) ,
    tp_escolaridade varchar(30),
    co_municipio_ibge_residencia char(50) ,
    co_municipio_ibge_ocorrencia char(50) ,
    co_cid_causa_basica varchar(10) ,
    desc_cid_causa_basica varchar(50) ,
    capitulo_cid_causa_basica varchar(50) ,
    categoria_cid_causa_basica varchar(50) 
);


copy tabela_principal from
    '/dados/tb_normalizacao/dados_cronicas_ses_2023.csv' DELIMITER ';' CSV HEADER ;

\set quiet off