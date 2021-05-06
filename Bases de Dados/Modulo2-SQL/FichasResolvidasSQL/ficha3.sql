-- Exercicios da 3º aula SQL - 2018/2019

-- 1. Obtenha os títulos editados em 2011.
SELECT TITULO 
FROM LIVROS
WHERE TO_CHAR(DATA_EDICAO, 'YYYY') = '2011';


-- 2. Output:
SELECT TO_CHAR(SYSDATE, 'HH24:MI:SS') AS "Hora Atual",
    TO_CHAR(SYSDATE, 'DD, Month, YYYY') AS "Data atual"
FROM DUAL;


-- 3. Seleccione o título e o preço dos livros editados há menos de 80 dias.
SELECT TITULO AS "Titulo", PRECO_TABELA AS "Preço"
FROM LIVROS
WHERE SYSDATE - DATA_EDICAO < 80;


-- 4. Mostre os livros adquiridos no intervalo de Agosto a Setembro de 2013 por
-- clientes de Lisboa.
SELECT L.TITULO
FROM LIVROS L, VENDAS V, CLIENTES C
WHERE L.CODIGO_LIVRO = V.CODIGO_LIVRO
AND V.CODIGO_CLIENTE = C.CODIGO_CLIENTE
AND C.MORADA LIKE '%Lisboa'
AND TO_CHAR(DATA_VENDA, 'YYYY-MM') IN ('2013-08', '2013-09');


-- 5. Obtenha o título dos livros de informática, independentemente do modo como o
-- género foi escrito (maiúsculas ou minúsculas), adquiridos no mês em que o livro
-- foi editado.
SELECT L.TITULO AS "Titulo", V.DATA_VENDA AS "Data Compra", L.DATA_EDICAO AS "Data Edicao"
FROM LIVROS L, VENDAS V
WHERE L.CODIGO_LIVRO = V.CODIGO_LIVRO
AND UPPER(GENERO)= 'INFORMÁTICA'
AND TO_CHAR(DATA_EDICAO, 'MM') = TO_CHAR(DATA_VENDA, 'MM');


-- 6. Mostre quais os autores que editaram livros de Informática no Verão de 2013
-- com mais do que 190 páginas. Considere que o Verão vai de 21 de Junho a 22
-- de Setembro.
SELECT A.NOME, L.DATA_EDICAO AS "Editado em"
FROM AUTORES A, LIVROS L
WHERE L.CODIGO_AUTOR = A.CODIGO_AUTOR
AND UPPER(GENERO)= 'INFORMÁTICA'
AND L.PAGINAS > 190
AND L.DATA_EDICAO >= TO_DATE('21-06-2013', 'DD-MM-YYYY')
AND L.DATA_EDICAO <= TO_DATE('22-09-2013', 'DD-MM-YYYY');


-- 7. Para cada livro de Informática, mostre há quantos anos foi editado.
SELECT TITULO , TO_CHAR(SYSDATE, 'YYYY')-TO_CHAR(DATA_EDICAO, 'YYYY') AS "Nº Anos"
FROM LIVROS;

-- 9. Mostre a lista dos autores que ainda não publicaram livros.
SELECT NOME 
FROM AUTORES 
MINUS 
SELECT DISTINCT NOME 
FROM AUTORES A, LIVROS L 
WHERE L.CODIGO_AUTOR = A.CODIGO_AUTOR;


-- 10. Mostre o nome dos autores que não tenham livros publicados, ou que tenha
-- publicado livros apenas este ano. Utilize MINUS.
SELECT NOME 
FROM AUTORES 
MINUS 
SELECT DISTINCT NOME 
FROM AUTORES A, LIVROS L 
WHERE L.CODIGO_AUTOR = A.CODIGO_AUTOR
AND TO_CHAR(DATA_EDICAO, ' YYYY') <> TO_CHAR(SYSDATE, 'YYYY');


-- Exercícios propostos -----------------------------------------------
--
-- a. Obtenha o dia da semana correspondente a 1 de Janeiro de 2000.
SELECT TO_CHAR( TO_DATE('01-01-2000','DD-MM-YYYY'), 'Day') AS "Dia da Semana"
FROM DUAL;


-- b. Output:
SELECT TITULO AS "Titulo",
    TO_CHAR(DATA_EDICAO, 'Month') AS "Mês de Edição",
    TO_CHAR(DATA_EDICAO, 'YYYY') AS "Ano de Edição"
FROM LIVROS;


--c. Para cada título, mostre a idade de cada autor quando este foi publicado.
SELECT L.TITULO AS "Titulo", 
    A.IDADE - FLOOR( (SYSDATE - L.DATA_EDICAO)/360) AS "Idade do Autor"
FROM LIVROS L, AUTORES A
WHERE L.CODIGO_AUTOR = A.CODIGO_AUTOR;


-- d. Output:
SELECT L.TITULO, C.NOME AS "NOME DO CLIENTE",
    TO_CHAR(V.DATA_VENDA,'Day') AS "DIA DA SEMANA",
    TO_CHAR(V.DATA_VENDA, 'hh:mm') AS "HORA DA COMPRA"
FROM LIVROS L, CLIENTES C, VENDAS V
WHERE L.CODIGO_LIVRO = V.CODIGO_LIVRO
AND V.CODIGO_CLIENTE = C.CODIGO_CLIENTE;


-- e. Mostre a lista dos autores que não publicaram livros este ano.
SELECT NOME
FROM AUTORES
MINUS 
SELECT L.NOME
FROM AUTORES A, LIVROS L
WHERE L.CODIGO_AUTOR = A.CODIGO_AUTOR
