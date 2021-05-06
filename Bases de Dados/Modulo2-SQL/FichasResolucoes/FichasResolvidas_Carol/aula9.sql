------ AULA 9 2016/2017
-- 1.
 create sequence exp_sequencia;
select exp_sequencia.currval from dual; -- precisa que primeiro se selecione nextval
select exp_sequencia.nextval from dual; -- vai incrementando à medida que é pedido
select exp_sequencia.nextval from dual;
select exp_sequencia.nextval from dual;
select exp_sequencia.currval from dual; -- depois de seleciona nextval, ele mostra o ultimo nextval
drop sequence exp_sequencia; 

--2.
CREATE TABLE EDITORAS_BACKUP
AS
  SELECT CODIGO_EDITORA, NOME, N_CONTRIBUINTE, MORADA, TELEFONE, FAX
  FROM EDITORAS;
  
--3.
CREATE SEQUENCE seq_editback
  INCREMENT BY 1
  START WITH 4
  NOMAXVALUE
  NOMINVALUE
  NOCYCLE
  NOCACHE;
  
--4.
INSERT INTO EDITORAS_BACKUP(CODIGO_EDITORA, NOME, N_CONTRIBUINTE, MORADA, TELEFONE, FAX)
VALUES (seq_editback.nextval,
        'D. Quixote', '901111111', 'Rua Cidade de Córdova, n.2 2610-038 Alfragide','707252252', '707252253');
        
--5.
SELECT seq_editback.currval from dual; --4
SELECT seq_editback.nextval from dual; --5
SELECT seq_editback.currval from dual; --5

--6.
DROP SEQUENCE seq_editback;
 
--7.
CREATE VIEW livros_informática
AS 
  SELECT TITULO
  FROM LIVROS
  WHERE GENERO = 'Informática';
  
--8. -- primeiros dois nao funcionam, porque?
INSERT INTO livros_informática (CODIGO_LIVRO, TITULO, ISBN, GENERO)
VALUES (30,'Uma noite de Verão', 8000000001,'Informática'); -- faltava o acento

INSERT INTO livros_informática (CODIGO_LIVRO, TITULO, ISBN, GENERO)
VALUES (31,'O céu é azul',8000000002,'Romance'); -- faltava o acento

INSERT INTO LIVROS (CODIGO_LIVRO, CODIGO_EDITORA, CODIGO_AUTOR, TITULO, ISBN, GENERO)
VALUES (32,2, 2,'Longe de tudo',8000000003,'Informática'); 

--9. ??

--10.
DROP VIEW livros_informática; 

--11.
CREATE TABLE LIVROS_BACKUP9
AS
  SELECT CODIGO_LIVRO, CODIGO_EDITORA, CODIGO_AUTOR, TITULO, ISBN, GENERO, PRECO_TABELA, PAGINAS, QUANT_EM_STOCK, UNIDADES_VENDIDAS, DATA_EDICAO
  FROM LIVROS;
  
--12.
CREATE VIEW autor_livro
AS
  SELECT UPPER(AUTORES.NOME) NOME_UPPER, UPPER(LIVROS_BACKUP9.TITULO) TITULO_UPPER
  FROM AUTORES, LIVROS_BACKUP9
  WHERE AUTORES.CODIGO_AUTOR=LIVROS_BACKUP9.CODIGO_AUTOR
  ORDER BY AUTORES.NOME;
  
--13.
SELECT NOME_UPPER, TITULO_UPPER
FROM autor_livro;

DELETE (SELECT *
        FROM LIVROS_BACKUP9);

SELECT NOME_UPPER, TITULO_UPPER
FROM autor_livro; -- aparece tudo em branco
--14.
DROP TABLE LIVROS_BACKUP9;

SELECT NOME_UPPER, TITULO_UPPER
FROM autor_livro; -- deu erro 04063  view "BD2C29.AUTOR_LIVRO" tem erros

--15. 16. 17. -- ERRO
CREATE VIEW livros_vendidos
AS
  SELECT LIVROS.TITULO, AUTORES.NOME, SUM(QUANTIDADE)
  FROM LIVROS, AUTORES, VENDAS
  WHERE AUTORES.CODIGO_AUTOR=LIVROS.CODIGO_AUTOR
  AND LIVROS.CODIGO_LIVRO=VENDAS.CODIGO_LIVRO
  ;
  
  SELECT *
  FROM VENDAS;