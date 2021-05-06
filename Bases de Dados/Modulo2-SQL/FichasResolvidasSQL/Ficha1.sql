-- Exercicios da 1º aula SQL - 2018/2019

-- 1. Seleccione toda a informação relativa aos autores
SELECT *
FROM AUTORES;

-- 2. Mostre os títulos dos livros publicados.
SELECT TITULO
FROM LIVROS;

-- 3. Seleccione todos os géneros de livros editados, evitando as repetições.
SELECT DISTINCT(GENERO)
FROM LIVROS;

-- 4. Seleccione o título dos livros cujo preço de tabela esteja entre 25 e 35.
SELECT DISTINCT GENERO
FROM LIVROS 
WHERE PRECO_TABELA BETWEEN 25 AND 45;

-- 5. Mostre o código e o título dos livros do género Informática.
SELECT CODIGO_LIVRO, TITULO
FROM LIVROS
WHERE GENERO='Informática';

-- 6. Seleccione o título dos livros policiais com mais de 500 páginas. 
SELECT TITULO
FROM LIVROS 
WHERE GENERO='Policial'
AND PAGINAS > 500;

-- 7. Seleccione os géneros dos livros que tenham mais de 700 páginas 
-- ou preço de tabela superior a 45.
SELECT DISTINCT GENERO 
FROM LIVROS
WHERE PAGINAS > 700 
OR PRECO_TABELA > 45;

-- 8. Mostre o título de todos os livros de Informática ordenados descendente pelo preço.
SELECT DISTINCT TITULO, PRECO_TABELA
FROM LIVROS
WHERE GENERO = 'Informática'
ORDER BY PRECO_TABELA DESC ;

-- 9. Mostre o ISBN, o título, preço de tabela e quantidade em stock dos livros de
-- Informática, ordenados descendentemente pelo preço de tabela e
-- ascendentemente pela quantidade em stock.
SELECT ISBN, TITULO, PRECO_TABELA, QUANT_EM_STOCK
FROM LIVROS 
WHERE GENERO = 'Informática'
ORDER BY PRECO_TABELA DESC, QUANT_EM_STOCK ASC;

-- 10.Qual o código dos autores cujos livros existem na livraria
SELECT DISTINCT CODIGO_AUTOR
FROM LIVROS 
WHERE QUANT_EM_STOCK > 0
ORDER BY 1 ASC ;

-- 11.Seleccione o título de todos os livros excepto os policiais.
SELECT TITULO
FROM LIVROS
WHERE GENERO <> 'Policial' ;

-- 12.Seleccione o título de todos os livros excepto os policiais, usando o NOT
SELECT TITULO
FROM LIVROS
WHERE NOT GENERO = 'Policial' ;

-- 13.Mostre o nome dos autores cuja idade seja superior a 30 anos e o género
-- preferido seja o Policial. Ordene o resultado ascendentemente pelo nome.
SELECT NOME
FROM AUTORES
WHERE IDADE > 30 
AND GENERO_PREFERIDO = 'Policial'
ORDER BY NOME ASC;

-- 14.Apresente o nome dos autores que contenham as letras ‘r’ e ‘d
SELECT NOME
FROM AUTORES 
WHERE NOME LIKE '%r%'
AND NOME LIKE '%d%';

-- 15.Seleccione o título dos livros que começam por ‘O’ e contêm a sequência de
-- letras ‘st’ e também os que começam por ‘M’ e contém a sequência ‘to’.
SELECT TITULO 
FROM LIVROS 
WHERE TITULO LIKE '%O%st%'
OR TITULO LIKE '%M%to%';

-- 16.Seleccione o título dos livros dos géneros policiais, romances e aventura.
SELECT TITULO 
FROM LIVROS
WHERE GENERO IN ('Policial', ' Romance', 'Aventura');

-- 17.Output:
SELECT 'O livro " ' || TITULO || ' " custa ' || PRECO_TABELA || ' euros. '
FROM LIVROS;



