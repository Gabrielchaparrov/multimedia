create or replace TRIGGER DESEMBOC_EUROPA 
BEFORE INSERT OR UPDATE OF PAIS_DESEMBOC ON RIOS FOR EACH ROW
DECLARE
cont_desemboc VARCHAR2(20);
BEGIN

    SELECT CONTINENTE INTO cont_desemboc FROM PAISES WHERE ID_PAIS = :NEW.PAIS_DESEMBOC;

    if(cont_desemboc != 'Europa') THEN
        raise_application_error(-20101, 'El continente de desembocadura no es Europa');
    end if;
    
END;


--UPDATE RIOS SET PAIS_DESEMBOC = 7 WHERE NOMBRE = 'Murray'
--INSERT INTO RIOS (ID_RIO, NOMBRE, LONGITUD, CUENCA, CAUDAL_MEDIO, NACIMIENTO, PAIS_NACIMIENTO, DESEMBOCADURA, PAIS_DESEMBOC) VALUES ('9', 'Prueba', '55', '55', '55', 'A', '1', 'b', '7')

