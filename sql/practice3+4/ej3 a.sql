 ---------------------------Práctica 4---------------------------

--EJERCICIO 3
--Transacción #3.1 -A

SET TRANSACTION ISOLATION LEVEL READ COMMITTED NAME 'Sesion A';

--Cambio de sesión

INSERT INTO DEPT (DEPTNO, DNAME, LOC) VALUES (151, 'ADVERTISING', 'VLC');

--Cambio de sesión

SELECT COUNT(*) FROM DEPT; --Devuelve 7
COMMIT;

--Transacción #3.2 -A

SET TRANSACTION ISOLATION LEVEL READ COMMITTED NAME 'Sesion A';

--Cambio de sesión

UPDATE DEPT SET DNAME='NEWNAME' WHERE DEPTNO=151;
COMMIT;