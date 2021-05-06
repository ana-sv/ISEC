-- Exercicios da 5º aula SQL - 2018/2019

-- ex 1 a
SELECT TITULO, PRECO_TABELA
FROM LIVROS
WHERE GENERO = 'Informática'
AND PRECO_TABELA = ( SELECT MAX(PRECO_TABELA)
                     FROM LIVROS 
                     WHERE GENERO = 'Informática' );
                        
-- ex 1 b 
SELECT TITULO , PRECO_TABELA
FROM LIVROS 
WHERE GENERO = 'Informática'
AND PRECO_TABELA >= ALL( SELECT PRECO_TABELA
                         FROM LIVROS 
                         WHERE GENERO = 'Informática' );
                        
-- ex 1 c
SELECT TITULO , PRECO_TABELA
FROM LIVROS L1
WHERE GENERO = 'Informática'
AND NOT EXISTS ( SELECT *
                 FROM LIVROS L2
                 WHERE L2.PRECO_TABELA > L1.PRECO_TABELA
                 AND GENERO = 'Informática' );
                 
-- ex 1 d
SELECT TITULO , PRECO_TABELA
FROM LIVROS , ( SELECT MAX(PRECO_TABELA) P
                FROM LIVROS 
                WHERE GENERO = 'Informática' ) PMAX
WHERE GENERO = 'Informática'
AND PRECO_TABELA = PMAX.P;


-- ex 2
SELECT DISTINCT A.NOME
FROM LIVROS L, AUTORES A
WHERE L.CODIGO_AUTOR = A.CODIGO_AUTOR
AND L.PAGINAS > (SELECT AVG(PAGINAS)
                 FROM LIVROS)
ORDER BY A.NOME;

-- ex 3 
SELECT A.NOME
FROM LIVROS L, AUTORES A
WHERE L.CODIGO_AUTOR = A.CODIGO_AUTOR
GROUP BY A.NOME
HAVING COUNT (L.CODIGO_LIVRO) > ( SELECT AVG( COUNT (*) )
                                  FROM LIVROS
                                  GROUP BY CODIGO_AUTOR )
ORDER BY A.NOME;

-- ex 4
SELECT L.TITULO, L.PRECO_TABELA AS PRECO, 
    PM.MEDIO AS PRECO_MEDIO, 
    L.PRECO_TABELA - PM.MEDIO AS DIFERENCA
FROM LIVROS L , ( SELECT CODIGO_AUTOR, ROUND( AVG(PRECO_TABELA),2 ) MEDIO
                   FROM LIVROS
                   GROUP BY CODIGO_AUTOR) PM
WHERE L.CODIGO_AUTOR = PM.CODIGO_AUTOR
AND GENERO = 'Informática';

-- ex 5 
SELECT L.GENERO, L.TITULO, L.UNIDADES_VENDIDAS
FROM LIVROS L, ( SELECT GENERO, MAX(UNIDADES_VENDIDAS) MAX
                 FROM LIVROS
                 GROUP BY GENERO) M
WHERE L.GENERO = M.GENERO
AND L.UNIDADES_VENDIDAS = M.MAX
ORDER BY 3 DESC;


-- ex 6 
SELECT L.TITULO, ROUND(  (L.UNIDADES_VENDIDAS/FCA.TOTAL*100) ,2)  AS "PERCENT"
FROM LIVROS L, EDITORAS E, ( SELECT SUM(L.UNIDADES_VENDIDAS) TOTAL
                             FROM LIVROS L , EDITORAS E
                             WHERE L.CODIGO_EDITORA=E.CODIGO_EDITORA
                             AND E.NOME LIKE 'FCA%') FCA
WHERE L.CODIGO_EDITORA=E.CODIGO_EDITORA
AND E.NOME LIKE 'FCA%'
ORDER BY 2 DESC;

-- ex 7
SELECT L.TITULO
FROM LIVROS L , CLIENTES C, VENDAS V
WHERE L.CODIGO_LIVRO=V.CODIGO_LIVRO
AND C.CODIGO_CLIENTE=V.CODIGO_CLIENTE
AND C.MORADA LIKE '%Lisboa'
GROUP BY TITULO 
HAVING SUM(QUANTIDADE) = ( SELECT MAX(SOMAQ) QMAX
                           FROM ( SELECT SUM(QUANTIDADE) SOMAQ
                                  FROM LIVROS L, CLIENTES C, VENDAS V
                                  WHERE L.CODIGO_LIVRO=V.CODIGO_LIVRO
                                  AND C.CODIGO_CLIENTE=V.CODIGO_CLIENTE
                                  AND C.MORADA LIKE '%Lisboa' 
                                  GROUP BY L.CODIGO_LIVRO ) TAB ); 
                    
                    
---- Exercicios Propostos ------------------------------

-- a

-- b

-- c