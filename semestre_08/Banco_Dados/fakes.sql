CREATE TABLE public.fakenames (
    number integer NOT NULL,
    gender character varying(6) NOT NULL,
    nameset character varying(25) NOT NULL,
    title character varying(6) NOT NULL,
    givenname character varying(20) NOT NULL,
    middleinitial character varying(1) NOT NULL,
    surname character varying(23) NOT NULL,
    streetaddress character varying(100) NOT NULL,
    city character varying(100) NOT NULL,
    state character varying(22) NOT NULL,
    statefull character varying(100) NOT NULL,
    zipcode character varying(15) NOT NULL,
    country character varying(2) NOT NULL,
    countryfull character varying(100) NOT NULL,
    emailaddress character varying(100) NOT NULL,
    username character varying(25) NOT NULL,
    password character varying(25) NOT NULL,
    browseruseragent character varying(255) NOT NULL,
    telephonenumber character varying(25) NOT NULL,
    telephonecountrycode integer NOT NULL,
    maidenname character varying(20) NOT NULL,
    birthday character varying(10) NOT NULL,
    age integer NOT NULL,
    tropicalzodiac character varying(11) NOT NULL,
    cctype character varying(10) NOT NULL,
    ccnumber character varying(16) NOT NULL,
    cvv2 character varying(3) NOT NULL,
    ccexpires character varying(10) NOT NULL,
    nationalid character varying(20) NOT NULL,
    upstracking character varying(24) NOT NULL,
    westernunionmtcn character(10) NOT NULL,
    moneygrammtcn character(8) NOT NULL,
    color character varying(6) NOT NULL,
    occupation character varying(70) NOT NULL,
    company character varying(70) NOT NULL,
    vehicle character varying(255) NOT NULL,
    domain character varying(70) NOT NULL,
    bloodtype character varying(3) NOT NULL,
    pounds character varying(5) NOT NULL,
    kilograms character varying(5) NOT NULL,
    feetinches character varying(6) NOT NULL,
    centimeters character varying(3) NOT NULL,
    guid character varying(36) NOT NULL,
    latitude numeric(10,6) NOT NULL,
    longitude numeric(10,6) NOT NULL
);

CREATE OR REPLACE VIEW public.fakes AS
 SELECT fakenames.number AS codigo,
    fakenames.gender AS genero,
    fakenames.givenname AS nome,
    fakenames.surname AS sobrenome,
    fakenames.streetaddress AS endereco,
    fakenames.city AS cidade,
    fakenames.state AS estado_sigla,
    fakenames.statefull AS estado,
    fakenames.emailaddress AS email,
    fakenames.username AS usuario,
    fakenames.password AS senha,
    fakenames.bloodtype AS tipo_sanguineo,
    fakenames.kilograms AS massa,
    fakenames.centimeters AS altura
   FROM fakenames;

CREATE OR REPLACE VIEW public.fakes3 AS
 SELECT codigo, genero, nome, sobrenome,
    massa::float,
    altura::float/100 AS altura
   FROM fakes;

CREATE OR REPLACE VIEW public.fakes4 AS
    SELECT codigo, genero, nome, sobrenome, massa, altura,
    massa/(altura*altura) AS imc
   FROM fakes3;

CREATE OR REPLACE VIEW public.fakes5 AS
    SELECT codigo, genero, nome,sobrenome, massa, altura, imc,
        CASE 
            WHEN imc < 18.5 THEN -1 --then eh a classe
            WHEN imc < 25 THEN 0
            WHEN imc < 30 THEN 1
            WHEN imc < 35 THEN 2
            ELSE 3
        END imc_classif
   FROM fakes4;

CREATE OR REPLACE VIEW public.fakes6 AS
    SELECT codigo, genero, nome,sobrenome, massa, altura, imc,
        CASE imc_classif
            WHEN -1 THEN 'Baixo'
            WHEN 0 THEN 'Normal'
            WHEN 1 THEN 'Sobre Peso'
            WHEN 2 THEN 'Obesidade'
            ELSE 'OBesidade Morbida'
        END imc_classif_texto
   FROM fakes5;
--COPY fakenames FROM
  --'/dados/fakenames.csv' csv header delimiter ';' quote '"';
  
-- WINDOWS
--COPY fakenames FROM
  --'D:\dados\fakenames.csv' csv header delimiter ';' quote '"';
  
-- LINUX
COPY fakenames FROM
  '/tmp/fakenames.csv' csv header delimiter ';' quote '"';
  
