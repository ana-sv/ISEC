-- Aula 18 Dez - Sessão1
-- Ficha Concorrencias 

--Exercicio 1-----------------------------------------
-- D
INSERT INTO CLIENTE_BACKUP
VALUES (11,'João Moreira', 1020304,
'Rua Palheiros das Ondas - 1030 775 Santarém', 243123456);

-- E 
SELECT * FROM CLIENTES_BACKUP;

-- G 
SELECT * FROM CLIENTES_BACKUP;

-- H 
COMMIT;
SELECT * FROM CLIENTS_BACKUP;


--Exercicio 2----------------------------------------

-- A
UPDATE CLIENTES_BACKUP
SET TELEFONE = '239333555'
WHERE CODIGO_CLIENTE = 8;

-- D 
COMMIT;


SELECT * FROM CLIENTES_BACKUP;


--Exercicio 3----------------------------------------

-- A 
SELECT * FROM FUNCIONARIO;

-- B
DROP TABLE FUNCIONARIO;

-- C
INSERT INT FUNCIORARIO
VALUES (8098098, 'JOAQUIM ALMEIDA', 259888333);
SELECT * FROM FUNCIONARIO;


--Exercicio 4 ---------------------------------------

-- A
UPDATE CLIENTES_BACKUP
SET TELEFONE = ' 239111111' 
WHERE CODIGO_CLIENTE = 1;

-- D 
UPDATE CLIENTES_BACKUP
SET N_CONTRIBUINTE = '29292929'
WHERE CODIGO_CLIENTE = 1;



