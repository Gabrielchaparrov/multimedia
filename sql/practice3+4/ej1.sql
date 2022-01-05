 ---------------------------Práctica 4---------------------------

--EJERCICIO 1
--Transacción #1.1
SET TRANSACTION READ WRITE;
INSERT INTO DEPT VALUES(50, 'HHRR', 'LOS ANGELES');
ROLLBACK;

--No se guarda

--Transacción #1.2
SET TRANSACTION READ WRITE;
INSERT INTO DEPT VALUES(50, 'HHRR', 'LOS ANGELES');
COMMIT;

--Se guarda

--Transacción #1.3
SET TRANSACTION READ WRITE;
INSERT INTO EMP (EMPNO, ENAME, JOB) VALUES(8001, 'JULIAN', 'CONSULTANT');

UPDATE EMP SET MGR='7839', HIREDATE='20/10/83', SAL='3500', COMM='0', DEPTNO='50' WHERE EMPNO='8001';

SAVEPOINT sp1;

UPDATE EMP SET MGR='7369', HIREDATE='20/10/83', SAL='3500', COMM=NULL, DEPTNO='40' WHERE EMPNO='8001';

ROLLBACK TO sp1;

--Comprobar -> resultados: En esta sesión se vuelve al estado anterior, en otra sesión no se ve porque no se ha hecho commit.

COMMIT;




