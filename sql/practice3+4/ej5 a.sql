---------------------------Práctica 4---------------------------

--EJERCICIO 5                   **SE EMPIEZAN LAS TRANSACCIONES AQUÍ, EN LA SESIÓN A
--Transacción #5.1 -A
SET TRANSACTION ISOLATION LEVEL READ COMMITTED NAME 'Sesion A';

--Cambio de sesión

LOCK TABLE DEPT IN SHARE MODE; --Lock correcto

--Cambio de sesión

SELECT COUNT(*) FROM DEPT; --Devuelve 10
COMMIT;

--Cambio de sesión

--Transacción #5.2 -A
SET TRANSACTION READ WRITE NAME 'Sesion A';

--Cambio de sesión

LOCK TABLE DEPT IN EXCLUSIVE MODE;

--Cambio de sesión

SELECT COUNT(*) FROM DEPT; --Devuelve 10
COMMIT;

--Cambio de sesión

--Share mode y Exclusive mode son diferentes, pero en el caso
--de que haya updates se comportan igual (en oracle)

--En el share no se permiten modificaciones, pero en este caso se realizan una vez se hace el commit y se desbloquea.