<?php
session_start();
if (isset($_SESSION['validado']))
{
    $correcto = $_SESSION['validado'];
    if ($correcto == true)
    {
        $userid = $_SESSION['userid'];
?>
<!DOCTYPE html>
<html>
<head>
<title>Felicidades</title>
</head>
<body>
<?php
        echo '<p>Felicidades, has accedido correctamente como el usuario:&nbsp;' . $userid . '</p>';
?>
   
    
    <form method="post" action="editarusuarios.php">
        <input type="submit" value="Editar Usuarios">
    </form>
    <br><br>
    <form method="post" action="editarpedidos.php">
        <input type="submit" value="Editar Pedidos">
    </form>
    <br><br>
    <form method="post" action="editarproductos.php">
        <input type="submit" value="Editar Productos">
    </form>
    <br><br>
    <form method="post" action="cerrarsesion.php">
        <input type="submit" value="Cerrar Sesión">
    </form>
    
</body>
</html>
<?php
    }
    else
    {
        header('Location: index.php');
    }
}
else
{
    header('Location: index.php');
}