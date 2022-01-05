---------------------------Práctica 4---------------------------

--EJERCICIO 5
--Transacción #5.1 -B
SET TRANSACTION ISOLATION LEVEL READ COMMITTED NAME 'Sesion B';

--Cambio de sesión
SELECT * FROM DEPT WHERE (DEPTNO = 110); --110 EJ43b_110_2 MADRID
SELECT * FROM DEPT WHERE (DEPTNO = 120) FOR UPDATE OF DEPTNO; --Se bloquea
UPDATE DEPT SET DNAME='EJ51' WHERE (DEPTNO = 120); --Aun está bloqueado

--Cambio de sesión

COMMIT; --Se guardan los cambios realizados, ya que se quedan bloqueados, pero alhacer commit en la otra sesión si que se puede modificar.

--Transacción #5.2 -B
SET TRANSACTION READ WRITE NAME 'Sesion B';

--Cambio de sesión

SELECT * FROM DEPT WHERE (DEPTNO = 110); --110 EJ43b_110_2 MADRID
SELECT * FROM DEPT WHERE (DEPTNO = 120) FOR UPDATE OF DEPTNO; --bloqueado
UPDATE DEPT SET DNAME='EJ52' WHERE (DEPTNO = 120); --bloqueado

--Cambio de sesión

COMMIT; --Se guardan los cambios realizados en la sesión B