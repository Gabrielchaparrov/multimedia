ALTER TABLE PAISES 
ADD (NUM_RIOS NUMBER DEFAULT 0);


create or replace TRIGGER NUM_RIOS_DESEMBOC 
BEFORE DELETE OR INSERT OR UPDATE ON RIOS FOR EACH ROW
DECLARE
num_rios_act INTEGER;
BEGIN

    IF INSERTING AND (:NEW.PAIS_DESEMBOC != :OLD.PAIS_DESEMBOC) THEN
        UPDATE PAISES SET NUM_RIOS = (SELECT NUM_RIOS FROM PAISES WHERE ID_PAIS = :NEW.PAIS_DESEMBOC)+1 WHERE ID_PAIS = :NEW.PAIS_DESEMBOC;
    END IF;
    
    IF UPDATING AND (:NEW.PAIS_DESEMBOC != :OLD.PAIS_DESEMBOC) THEN
        UPDATE PAISES SET NUM_RIOS = (SELECT NUM_RIOS FROM PAISES WHERE ID_PAIS = :NEW.PAIS_DESEMBOC)+1 WHERE ID_PAIS = :NEW.PAIS_DESEMBOC;
        UPDATE PAISES SET NUM_RIOS = (SELECT NUM_RIOS FROM PAISES WHERE ID_PAIS = :OLD.PAIS_DESEMBOC)-1 WHERE ID_PAIS = :OLD.PAIS_DESEMBOC;
    END IF;
    
    IF DELETING AND (:NEW.PAIS_DESEMBOC != :OLD.PAIS_DESEMBOC) THEN
        UPDATE PAISES SET NUM_RIOS = (SELECT NUM_RIOS FROM PAISES WHERE ID_PAIS = :OLD.PAIS_DESEMBOC)-1 WHERE ID_PAIS = :OLD.PAIS_DESEMBOC;
    END IF;
    
END;


--UPDATE RIOS SET PAIS_DESEMBOC = 7 WHERE NOMBRE = 'Murray'
--INSERT INTO RIOS (ID_RIO, NOMBRE, LONGITUD, CUENCA, CAUDAL_MEDIO, NACIMIENTO, PAIS_NACIMIENTO, DESEMBOCADURA, PAIS_DESEMBOC) VALUES ('9', 'Prueba', '55', '55', '55', 'A', '1', 'b', '7')
