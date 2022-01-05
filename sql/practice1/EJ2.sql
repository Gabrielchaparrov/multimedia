create or replace TRIGGER RIOS_CAUD
BEFORE INSERT OR UPDATE OF CAUDAL_MEDIO ON RIOS FOR EACH ROW

BEGIN
    if(:NEW.CAUDAL_MEDIO <= 0 or :NEW.CAUDAL_MEDIO > 230000) THEN
        raise_application_error(-20101, 'El caudal introducido: (' || :NEW.CAUDAL_MEDIO || ') no es v�lido');
    end if;

END;

create or replace TRIGGER RIOS_LONG 
BEFORE INSERT OR UPDATE OF LONGITUD ON RIOS FOR EACH ROW

BEGIN
    if(:NEW.LONGITUD <= 0 or :NEW.LONGITUD > 7100) THEN
        raise_application_error(-20101, 'La longitud introducida: (' || :NEW.LONGITUD || ') no es v�lida');
    end if;

END;

--a) Inserir un riu amb una longitud permesa (INSERT) y consultar la taula per a comprovar que ha funcionat la inserci� (SELECT) 
INSERT INTO "GIISGBD401"."RIOS" (ID_RIO, NOMBRE, LONGITUD, CUENCA, CAUDAL_MEDIO, NACIMIENTO, PAIS_NACIMIENTO, DESEMBOCADURA, PAIS_DESEMBOC) VALUES ('80', 'PRUEBA_OK', '300', '100', '50', 'NACIEMIENTO', '1', 'DESEMBOCADURA', '4')

--SELECT * FROM RIOS WHERE NOMBRE = 'PRUEBA_OK'

--b) Modificar un riu amb una longitud no permesa (UPDATE) y mostrar l�error que genera el SGBD 
UPDATE RIOS SET LONGITUD = '-50' WHERE NOMBRE = 'PRUEBA_OK'

--Error que empieza en la l�nea: 1 del comando :
--UPDATE RIOS SET LONGITUD = '-50' WHERE NOMBRE = 'PRUEBA_OK'
--Informe de error -
--ORA-20101: La longitud introducida: (-50) no es v�lida
--ORA-06512: en "GIISGBD401.RIOS_LONG", l�nea 3
--ORA-04088: error durante la ejecuci�n del disparador 'GIISGBD401.RIOS_LONG'

--c) Deshabilitar el trigger (sent�ncia SQL) creat 
ALTER TRIGGER RIOS_LONG DISABLE;
--Trigger RIOS_LONG alterado.

--d) Repetir l�operaci� de modificaci� i consultar la taula per a comprovar que la dada de longitud incorrecta s�ha inserit (SELECT) 
UPDATE RIOS SET LONGITUD = '-50' WHERE NOMBRE = 'PRUEBA_OK'
--1 fila actualizadas.

--e) Habilitar el trigger (sent�ncia SQL) 
ALTER TRIGGER RIOS_LONG ENABLE;

--f) Executar un ROLLBACK per a desfer la transacci� i comentar el resultat obtingut. 
ROLLBACK;