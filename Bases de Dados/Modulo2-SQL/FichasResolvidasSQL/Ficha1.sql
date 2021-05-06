-- Exercicios da 1� aula SQL - 2018/2019

-- 1. Seleccione toda a informa��o relativa aos autores
SELECT *
FROM AUTORES;

-- 2. Mostre os t�tulos dos livros publicados.
SELECT TITULO
FROM LIVROS;

-- 3. Seleccione todos os g�neros de livros editados, evitando as repeti��es.
SELECT DISTINCT(GENERO)
FROM LIVROS;

-- 4. Seleccione o t�tulo dos livros cujo pre�o de tabela esteja entre 25 e 35.
SELECT DISTINCT GENERO
FROM LIVROS 
WHERE PRECO_TABELA BETWEEN 25 AND 45;

-- 5. Mostre o c�digo e o t�tulo dos livros do g�nero Inform�tica.
SELECT CODIGO_LIVRO, TITULO
FROM LIVROS
WHERE GENERO='Inform�tica';

-- 6. Seleccione o t�tulo dos livros policiais com mais de 500 p�ginas. 
SELECT TITULO
FROM LIVROS 
WHERE GENERO='Policial'
AND PAGINAS > 500;

-- 7. Seleccione os g�neros dos livros que tenham mais de 700 p�ginas 
-- ou pre�o de tabela superior a 45.
SELECT DISTINCT GENERO 
FROM LIVROS
WHERE PAGINAS > 700 
OR PRECO_TABELA > 45;

-- 8. Mostre o t�tulo de todos os livros de Inform�tica ordenados descendente pelo pre�o.
SELECT DISTINCT TITULO, PRECO_TABELA
FROM LIVROS
WHERE GENERO = 'Inform�tica'
ORDER BY PRECO_TABELA DESC ;

-- 9. Mostre o ISBN, o t�tulo, pre�o de tabela e quantidade em stock dos livros de
-- Inform�tica, ordenados descendentemente pelo pre�o de tabela e
-- ascendentemente pela quantidade em stock.
SELECT ISBN, TITULO, PRECO_TABELA, QUANT_EM_STOCK
FROM LIVROS 
WHERE GENERO = 'Inform�tica'
ORDER BY PRECO_TABELA DESC, QUANT_EM_STOCK ASC;

-- 10.Qual o c�digo dos autores cujos livros existem na livraria
SELECT DISTINCT CODIGO_AUTOR
FROM LIVROS 
WHERE QUANT_EM_STOCK > 0
ORDER BY 1 ASC ;

-- 11.Seleccione o t�tulo de todos os livros excepto os policiais.
SELECT TITULO
FROM LIVROS
WHERE GENERO <> 'Policial' ;

-- 12.Seleccione o t�tulo de todos os livros excepto os policiais, usando o NOT
SELECT TITULO
FROM LIVROS
WHERE NOT GENERO = 'Policial' ;

-- 13.Mostre o nome dos autores cuja idade seja superior a 30 anos e o g�nero
-- preferido seja o Policial. Ordene o resultado ascendentemente pelo nome.
SELECT NOME
FROM AUTORES
WHERE IDADE > 30 
AND GENERO_PREFERIDO = 'Policial'
ORDER BY NOME ASC;

-- 14.Apresente o nome dos autores que contenham as letras �r� e �d
SELECT NOME
FROM AUTORES 
WHERE NOME LIKE '%r%'
AND NOME LIKE '%d%';

-- 15.Seleccione o t�tulo dos livros que come�am por �O� e cont�m a sequ�ncia de
-- letras �st� e tamb�m os que come�am por �M� e cont�m a sequ�ncia �to�.
SELECT TITULO 
FROM LIVROS 
WHERE TITULO LIKE '%O%st%'
OR TITULO LIKE '%M%to%';

-- 16.Seleccione o t�tulo dos livros dos g�neros policiais, romances e aventura.
SELECT TITULO 
FROM LIVROS
WHERE GENERO IN ('Policial', ' Romance', 'Aventura');

-- 17.Output:
SELECT 'O livro " ' || TITULO || ' " custa ' || PRECO_TABELA || ' euros. '
FROM LIVROS;



