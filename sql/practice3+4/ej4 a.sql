---------------------------Práctica 4---------------------------

--EJERCICIO 4                   **SE EMPIEZAN LAS TRANSACCIONES AQUÍ, EN LA SESIÓN A
--Transacción #4.1 -A
SET TRANSACTION READ WRITE NAME 'Sesion A';

INSERT INTO DEPT VALUES (101, 'PRIVACY', 'VALENCIA'); --Se inserta

COMMIT;

--Cambio de sesión

UPDATE DEPT SET DEPTNO=102 WHERE DEPTNO=101; --Se actualiza

--Cambio de sesión

COMMIT;

--Cambio de sesión


--Transacción #4.2 -A
SET TRANSACTION READ WRITE NAME 'Sesion A';

--Cambio de sesión

SELECT * FROM DEPT WHERE (DEPTNO >= 100) FOR UPDATE OF DEPTNO; --2 filas

--Cambio de sesión

UPDATE DEPT SET DEPTNO=(DEPTNO-10) WHERE (DEPTNO >= 100); --2 filas actualizadas
SELECT COUNT(*) FROM DEPT WHERE (DEPTNO < 100); --Devuelve 7

--Cambio de sesión

COMMIT;

--Cambio de sesión


--Transacción #4.3 -A
SET TRANSACTION READ WRITE NAME 'Sesion A';

--Cambio de sesión

INSERT INTO DEPT (DEPTNO, DNAME, LOC) VALUES (110, 'EJ43A_110_1', 'MADRID'); --Se inserta
COMMIT;

--Cambio de sesión

SELECT * FROM DEPT WHERE (DEPTNO = 110) FOR UPDATE OF DEPTNO; --110 ej43a_110_1 MADRID

--Cambio de sesión

UPDATE DEPT SET DNAME='EJ43A_110_2' WHERE (DEPTNO = 110); --Se actualiza

--Cambio de sesión

SELECT * FROM DEPT WHERE (DEPTNO = 120) FOR UPDATE OF DEPTNO; --Se bloquea porque lo tiene bloqueado la otra sesión

--Cambio de sesión

UPDATE DEPT SET DNAME='EJ43A_120_2' WHERE (DEPTNO = 120); --Sigue bloqueado

--Cambio de sesión

COMMIT;


--Ocurren múltiples bloqueos, pero los cambios insertados se realizan con éxito.
--Las modificaciones que se quedan guardadas son las que se realizan en la sesión B, es decir, los nombres EJ43b_120_2 y EJ43b_110_2.
--La modificación del departamento 110 es posible ya que al principio se bloquea pero al hacer commit en la sesión A se desbloquea y puede modifcar su nombre. (Línea 14 del enunciado)






