-- Aula 18 Dez - Sessão2
-- Ficha Concorrencias 

--Exercicio 1-----------------------------------------
-- E 
SELECT * FROM CLIENTES_BACKUP;

-- G 
SELECT * FROM CLIENTES_BACKUP;

-- I 
ROLLBACK; 



--Exercicio 2-----------------------------------------

-- B 
UPDATE CLIENTES_BACKUP
SET NOME = 'MANUEL MOREIRA'
WHERE CODIGO_CLIENTE = 11;

-- C 
UPDATE CLIENTES_BACKUP
SET MORADA = 'Rua Ferreira Borges'
WHERE CODIGO_CLIENTE = 8;

SELECT * FROM CLIENTES_BACKUP;

-- E
CREATE TABLE FUNCIONARIO(
    NIF NUMBER PRIMARY KEY,
    NOME VARCHAR(40),
    TELEFONE NUMBER );
    
SELECT * FROM CLIENTES_BACKUP;


--Exercicio 3-----------------------------------------
-- A 
INSERT INT FUNCIORARIO
VALUES (8098098, 'JOAQUIM ALMEIDA', 259888333);
SELECT * FROM FUNCIONARIO;

COMMIT;DROP TABLE FUNCIONARIO;


--Exercicio 4-----------------------------------------

-- B
UPDATE CLIENTES_BACKUP
SET TELEFONE = ' 239222222' 
WHERE CODIGO_CLIENTE = 2;

-- C
UPDATE CLIENTES_BACKUP
SET N_CONTRIBUINTE = '71717171';
WHERE CODIGO_CLIENTE = 1;

