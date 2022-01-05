---------------------------Práctica 4---------------------------

--EJERCICIO 4
--Transacción #4.1 -B
SET TRANSACTION READ WRITE NAME 'Sesion B';

--Cambio de sesión

UPDATE DEPT SET DEPTNO=DEPTNO+5 WHERE DEPTNO=101; --Se queda cargando, porque no sabe que se ha cambiado el nº y piensa que si que existe
UPDATE DEPT SET DEPTNO=DEPTNO+5 WHERE DEPTNO=102; --0 filas actualizadas, no se ha hecho el commit de la otra sesión

--Cambio de sesión

COMMIT;

--Transacción #4.2 -B
SET TRANSACTION READ WRITE NAME 'Sesion B';

--Cambio de sesión

SELECT COUNT(*) FROM DEPT WHERE (DEPTNO < 100); --Devuelve 6

--Cambio de sesión

SELECT COUNT(*) FROM DEPT WHERE (DEPTNO < 100); --Sigue devolviendo 6 porque en la otra sesión no se ha hecho commit

--Cambio de sesión

COMMIT;

--Transacción #4.3 -B
SET TRANSACTION READ WRITE NAME 'Sesion B';

--Cambio de sesión

INSERT INTO DEPT (DEPTNO, DNAME, LOC) VALUES (120, 'EJ43b_120_1', 'MADRID'); --Se inserta
COMMIT;

--Cambio de sesión

SELECT * FROM DEPT WHERE (DEPTNO = 120) FOR UPDATE OF DEPTNO; --120 ej43B_120_1 MADRID

--Cambio de sesión

UPDATE DEPT SET DNAME='EJ43b_120_2' WHERE (DEPTNO = 120); --Se actualiza

--Cambio de sesión

SELECT * FROM DEPT WHERE (DEPTNO = 110) FOR UPDATE OF DEPTNO; --Se bloquea porque la otra sesión lo tiene bloqueado

--Cambio de sesión

UPDATE DEPT SET DNAME='EJ43b_110_2' WHERE (DEPTNO = 110); --Se queda bloqueado porque la otra sesión lo tiene bloqueado

--Cambio de sesión

COMMIT;


