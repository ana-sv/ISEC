------ AULA 8 2016/2017
1.
CREATE TABLE AUTORES2  --- ERRO
                    (CODIGO_AUTOR NUMBER(4) CONSTRAINT autor_codautor_pk PRIMARY KEY,
                     NOME VARCHAR(30) CONSTRAINT autor_nome_ck CHECK(NOME=UPPER(NOME)),
                     N_CONTRIBUINTE NUMBER(9) UNIQUE,
                     MORADA VARCHAR(50),
                     IDADE NUMBER(4) CONSTRAINT autor_idade_ck CHECK(IDADE<200),
                     SEXO CHAR(1),
                     NACIONALIDADE VARCHAR(20),
                     GENERO_PREFERIDO VARCHAR(20));

2.
CREATE TABLE AVALIACOES --- ERRO
                      (CODIGO_LIVRO NUMBER(4),
                      CODIGO_CLIENTE NUMBER(4),
                      NOTA NUMBER(1),
                      CONSTRAINT AVALIACOES_CODLIVRO_FK FOREIGN KEY(CODIGO_LIVRO) REFERENCES LIVROS(CODIGO_LIVRO),
                      CONSTRAINT AVALIACOES_CODCLIENTE_FK FOREIGN KEY(CODIGO_CLIENTE) REFERENCES CLIENTES(CODIGO_CLIENTE),
                      CONSTRAINT AVALIACOES_PK PRIMARY KEY(CODIGO_LIVRO, CODIGO_CLIENTE));

3.
CREATE TABLE LIVROS_BACKUP 
AS 
  SELECT CODIGO_LIVRO, CODIGO_EDITORA, CODIGO_AUTOR, TITULO, ISBN, UPPER(GENERO), PRECO_TABELA, PAGINAS, QUANT_EM_STOCK, UNIDADES_VENDIDAS, DATA_EDICAO
  FROM LIVROS;
  
4.
ALTER TABLE LIVROS_BACKUP  
ADD CONSTRAINT BACKUP_CODLIVRO_PK PRIMARY KEY(CODIGO_LIVRO);

ALTER TABLE LIVROS_BACKUP  
ADD CONSTRAINT BACKUP_CODEDITORA_FK FOREIGN KEY(CODIGO_EDITORA) REFERENCES EDITORAS(CODIGO_EDITORA);

ALTER TABLE LIVROS_BACKUP  
ADD CONSTRAINT BACKUP_CODAUTOR_FK FOREIGN KEY(CODIGO_AUTOR) REFERENCES AUTORES(CODIGO_AUTOR);

5.
INSERT INTO LIVROS_BACKUP (CODIGO_LIVRO, CODIGO_EDITORA, CODIGO_AUTOR, TITULO, ISBN, GENERO, PRECO_TABELA, PAGINAS)
VALUES (51, 1, 1, 'Informática para todos', 132434, 'Informática', 24, 430);

6.
INSERT INTO AUTORES2 (CODIGO_AUTOR, NOME, N_CONTRIBUINTE)
VALUES (45, 'José de Magalhães', 77665544);

7.
DELETE FROM LIVROS_BACKUP
WHERE CODIGO_LIVRO = 51;

8.
UPDATE LIVROS_BACKUP
SET PRECO_TABELA = PRECO_TABELA * 1.10
WHERE GENERO='AVENTURA';

9.
DELETE FROM LIVROS_BACKUP
WHERE GENERO = 'INFORMÁTICA' AND PRECO_TABELA <
                                                (SELECT AVG(PRECO_TABELA)
                                                FROM LIVROS_BACKUP
                                                WHERE GENERO = 'INFORMÁTICA');
                                                
10.
CREATE TABLE AUTORES_BACKUP 
AS
  SELECT CODIGO_AUTOR, NOME, N_CONTRIBUINTE, MORADA, IDADE, SEXO, NACIONALIDADE, GENERO_PREFERIDO
  FROM AUTORES;

11.