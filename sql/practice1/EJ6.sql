CREATE OR REPLACE TRIGGER MUTANTE_PAIS
AFTER DELETE ON PAISES
FOR EACH ROW
DECLARE n INTEGER;
BEGIN
    SELECT COUNT(*) INTO n FROM PAISES;
    DBMS_OUTPUT.PUT_LINE('Hay ' || n || 'paises.');
END;

--DELETE FROM PAISES WHERE NOMBRE = 'Italia'