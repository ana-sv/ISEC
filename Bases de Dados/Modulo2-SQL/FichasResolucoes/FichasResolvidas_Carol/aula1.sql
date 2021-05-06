------ AULA 1 2016/2017


SELECT * 
FROM AUTORES;

SELECT TITULO 
FROM LIVROS;

SELECT sysdate
FROM DUAL;

SELECT GENERO
FROM LIVROS;

SELECT DISTINCT GENERO
FROM LIVROS;

SELECT TITULO
FROM LIVROS
WHERE PRECO_TABELA>25 AND PRECO_TABELA<35;

SELECT CODIGO_LIVRO, TITULO
FROM LIVROS
WHERE GENERO='Informática';

SELECT TITULO
FROM LIVROS
WHERE GENERO='Policial' AND PAGINAS>500;

SELECT GENERO
FROM LIVROS
WHERE PAGINAS>700 AND PRECO_TABELA>45;

SELECT TITULO, PRECO_TABELA
FROM LIVROS
WHERE GENERO='Informática'
ORDER BY PRECO_TABELA DESC;

SELECT ISBN, TITULO, PRECO_TABELA, QUANT_EM_STOCK
FROM LIVROS
WHERE GENERO='Informática'
ORDER BY PRECO_TABELA DESC, QUANT_EM_STOCK ASC;

SELECT CODIGO_AUTOR
FROM LIVROS;

SELECT TITULO
FROM LIVROS
WHERE GENERO!='Policial';

SELECT TITULO
FROM LIVROS 
WHERE GENERO NOT IN 'Policial';

SELECT NOME
FROM AUTORES
WHERE IDADE>30 AND GENERO_PREFERIDO='Policial'
ORDER BY NOME ASC;

-- quando se coloca '%letra%' estamos à procura dessa letra no meio da palavra
-- se fosse '_letra_' estariamos à procura dessa letra com um caracter de diferença entre o fim e o inicio da palavra
SELECT NOME
FROM AUTORES
WHERE NOME like '%r%' AND NOME like '%d%';

SELECT TITULO
FROM LIVROS
WHERE TITULO like 'O%' AND TITULO like '%st%' OR TITULO like 'M%' AND TITULO like '%to%';
--OU
SELECT TITULO
FROM LIVROS
WHERE TITULO like 'O%st%' OR TITULO like 'M%to%';

SELECT TITULO
FROM LIVROS
WHERE GENERO='Policial' OR GENERO='Romance' OR GENERO='Aventura';

SELECT 'O livro "'||TITULO||'" custa '||PRECO_TABELA||' euros.' "Listagem de livros"
FROM LIVROS;