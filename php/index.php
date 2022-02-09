<!DOCTYPE html>
<html>
<head>
<title>Ejemplo de validación</title>
<meta charset="UTF-8">
</head>
<body>
    
    <?php
session_unset();
session_start();
$_SESSION['validado'] = false;
?>
   
    <form method="post" action="validaradminphp.php">

        <p>Usuario:&nbsp;<input type="text" name="usuario" value=""></p>
        <p>Clave:&nbsp;<input type="password" name="clave" value=""></p>
        <p><input type="submit" value="Acceder"></p>
        
    </form>
    
    
        <?php
?>
   
    
    
</body>
</html>