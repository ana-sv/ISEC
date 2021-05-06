-- Exercicios da 2º aula SQL - 2018/2019


-- 1. Mostre o título dos livros Policiais do autor Cláudio Tereso.
SELECT TITULO
FROM LIVROS, AUTORES
WHERE LIVROS.CODIGO_AUTOR=AUTORES.CODIGO_AUTOR
AND GENERO = 'Policial'
AND NOME = 'Cláudio Tereso';


-- 2. Mostre o título dos livros Policiais escritos por autores de Coimbra
SELECT TITULO 
FROM LIVROS, AUTORES
WHERE LIVROS.CODIGO_AUTOR=AUTORES.CODIGO_AUTOR
AND GENERO = 'Policial'
AND MORADA LIKE '%Coimbra%';


-- 3. Qual o nome dos autores que escreveram livros do seu género preferido.
SELECT DISTINCT NOME
FROM AUTORES, LIVROS 
WHERE AUTORES.CODIGO_AUTOR=LIVROS.CODIGO_AUTOR
AND LIVROS.GENERO = AUTORES.GENERO_PREFERIDO;


-- 4. Mostre o título e o preço de tabela dos livros adquiridos por clientes de Coimbra.
SELECT TITULO, PRECO_TABELA PRECO 
FROM LIVROS L, VENDAS V, CLIENTES C
WHERE L.CODIGO_LIVRO=V.CODIGO_LIVRO
AND V.CODIGO_CLIENTE=C.CODIGO_CLIENTE
AND MORADA LIKE '%Coimbra';


-- 5. Mostre quais os autores que compraram livros na livraria.
SELECT TITULO
FROM AUTORES A,LIVROS L, VENDAS V, CLIENTES C
WHERE A.CODIGO_AUTOR = L.CODIGO_AUTOR
AND L.CODIGO_LIVRO = V.CODIGO_LIVRO
AND V.CODIGO_CLIENTE = C.CODIGO_CLIENTE
AND A.NOME = C.NOME;


-- 6. Mostre, para cada autor, quais os livros que escreveu cujos géneros não são o
-- género preferido do autor. Ordene o resultado pelo nome do autor.
SELECT A.NOME "NOME DO AUTOR", L.TITULO, L.GENERO
FROM AUTORES A, LIVROS L
WHERE A.CODIGO_AUTOR=L.CODIGO_AUTOR
AND L.GENERO <> A.GENERO_PREFERIDO
ORDER BY A.NOME;


-- 7. Supondo que o autor recebe 30% do preço de tabela de cada livro,
-- quanto rendeu cada livro ao seu autor?
SELECT TITULO, ( UNIDADES_VENDIDAS * PRECO_TABELA * 0.3 ) "Rendeu"
FROM LIVROS;


-- 8. Obtenha o título dos livros que renderam mais de 10000 euros ao seu autor.
-- Ordene o resultado por género e preço.
SELECT TITULO, ( UNIDADES_VENDIDAS *PRECO_TABELA * 0.3 ) AS "Rendimento"
FROM LIVROS 
WHERE ( UNIDADES_VENDIDAS * PRECO_TABELA * 0.3 ) > 10000
ORDER BY GENERO, PRECO_TABELA;


-- 9. Para os livros com um número de páginas entre 400 e 700, calcule o custo por
-- página arredondado à 2ª casa decimal e o valor inteiro (em euros) superior e
-- inferior. O resultado deve ser ordenado pelo custo por página.
SELECT TITULO,
    ROUND(PRECO_TABELA/PAGINAS,2) AS "Custo página",
    CEIL(PRECO_TABELA/PAGINAS ) AS "Custo pág(sup)",
    FLOOR(PRECO_TABELA/PAGINAS) AS "Custo pág.(inf)"
FROM LIVROS
WHERE PAGINAS BETWEEN 400 AND 700
ORDER BY "Custo página";


-- 10.Obtenha o título em maiúsculas, minúsculas e com a primeira letra de cada
-- palavra maiúscula e restantes minúsculas dos livros editados.
SELECT UPPER(TITULO) AS "Titulo (em maiúsculas)",
    LOWER(TITULO) AS "Titulo (em minúsculas)" ,
    INITCAP(TITULO) AS "Titulo (1º letra maiúscula)"
FROM LIVROS;


-- 11.Obtenha o título dos livros de informática, independentemente do modo como o
-- género foi escrito (maiúsculas ou minúsculas).
SELECT TITULO
FROM LIVROS
WHERE UPPER(GENERO) = 'INFORMÁTICA';

-- ou 
SELECT TITULO
FROM LIVROS
WHERE UPPER(GENERO) LIKE 'INFORMÁTICA';


-- 12.Para cada autor, obtenha o nome completo, o seu primeiro e o último nome.
SELECT NOME AS "Nome Completo",
    SUBSTR(NOME ,1 , INSTR(NOME, ' ') - 1) AS "Primeiro Nome" ,
    SUBSTR(NOME ,INSTR(NOME, ' ', -1) +1) AS "Ultimo Nome"
FROM AUTORES;

--------- notas ? ------------------------------------------------------------
--INITCAP(string1, string2) -> devolve a posição da string procurada
---> string1 = string procurada
---> string2 = string onde se procura

--SUBSTR(string, start, length)
--ou 
--SUBSTR(string FROM start FOR length)
---> devolve a diferença entre o tamanho(length) da string e o ponto start
----------------------------------------------------------------------------


-- 13.Mostre o título, o género e o nome do autor dos livros editados pela 
-- editora ‘FCA - EDITORA’. O título do livro deverá aparecer em maiúsculas, 
-- o género em minúsculas e o nome do autor com a primeira letra maiúscula e 
-- o resto em minúsculas. Ordene o resultado por nome do autor.
SELECT UPPER(L.TITULO) AS "Titulo (em maiúsculas)",
    LOWER(L.GENERO) AS "genero (min)",
    INITCAP(A.NOME) AS "Nome Autor (1ºletra)"
FROM LIVROS L, AUTORES A, EDITORAS E 
WHERE A.CODIGO_AUTOR =  L.CODIGO_AUTOR
AND L.CODIGO_EDITORA = E.CODIGO_EDITORA
AND E.NOME = 'FCA - EDITORA'
ORDER BY 3;


-- 14.Quais os livros cujo título tem mais de 20 caracteres.
SELECT TITULO
FROM LIVROS 
WHERE LENGTH(TITULO) > 20;


-- 15.Para os livros Policiais, mostre o título, o preço e o preço com um aumento de
-- 13,55%. O preço depois do aumento deverá ser arredondado na primeira casa decimal.
SELECT TITULO, PRECO_TABELA AS PRECO,
    ROUND( PRECO_TABELA + PRECO_TABELA*0.1355 , 1 ) AS "PRECO_COM_AUMENTO"
FROM LIVROS
WHERE GENERO LIKE 'Policial';


-- Exercícios Propostos:

-- a. Seleccione os títulos e o género dos livros que não sejam dos géneros policiais e
-- romances, assim como os que comecem pela letra ‘O’.
SElECT TITULO, GENERO
FROM LIVROS
WHERE GENERO <> 'Policial'
AND GENERO <> 'Romance'
AND TITULO NOT LIKE '%O';

-- b. Output:
SELECT TITULO AS "Titulo",
    PRECO_TABELA AS "Precos em euros",
    ROUND(PRECO_TABELA*200.48,2) AS "Precos em Escudos"
FROM LIVROS;


-- c. Output:  WTF? :) 

-- d. Quais os clientes que compraram livros editados pela FCA-EDITORA escritos
-- por autores que moram na mesma cidade.
SELECT DISTINCT L.TITULO, C.NOME AS "Nome de Cliente", A.NOME AS "Nome de Autor"
FROM LIVROS L, AUTORES A, VENDAS V, CLIENTES C, EDITORAS E
WHERE E.CODIGO_EDITORA = L.CODIGO_EDITORA
AND L.CODIGO_AUTOR = A.CODIGO_AUTOR
AND L.CODIGO_LIVRO = V.CODIGO_LIVRO
AND V.CODIGO_CLIENTE = C.CODIGO_CLIENTE
AND E.NOME = 'FCA - EDITORA'
AND SUBSTR(C.MORADA,INSTR(C.MORADA, ' ',-1)+1) = SUBSTR(A.MORADA,INSTR(A.MORADA, ' ',-1)+1) ;


-- e. Mostre o título dos livros escritos por autores cujo último nome seja Loureiro.
SELECT TITULO 
FROM LIVROS L, AUTORES A
WHERE L.CODIGO_AUTOR = A.CODIGO_AUTOR
AND SUBSTR(A.NOME,INSTR(A.NOME, ' ',-1)+1) = 'Loureiro';

-- f. O mesmo que no exercício número 15, mas com o preço depois do aumento (?)
-- arredondado para um número inteiro.
SELECT TITULO, GENERO, PRECO_TABELA, 
    ROUND( PRECO_TABELA + PRECO_TABELA*0.1355 , 0 ) AS "PRECO_COM_AUMENTO"
FROM LIVROS
ORDER BY GENERO;




