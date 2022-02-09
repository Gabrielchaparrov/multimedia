<?php
session_start();
if (isset($_SESSION['validado']))
{
    $correcto = $_SESSION['validado'];
    if ($correcto == true)
    {
        $userid = $_SESSION['userid'];
?>

<?php
        session_start();
        $codigo    = $_REQUEST['codigo'];
        $activo    = $_REQUEST['activo'];
        $usuario   = $_REQUEST['usuario'];
        $clave     = $_REQUEST['clave'];
        $admin     = $_REQUEST['admin'];
        $nombre    = $_REQUEST['nombre'];
        $apellidos = $_REQUEST['apellidos'];
        $domicilio = $_REQUEST['domicilio'];
        $poblacion = $_REQUEST['poblacion'];
        $provincia = $_REQUEST['provincia'];
        $cp        = $_REQUEST['cp'];
        $telefono  = $_REQUEST['telefono'];
        $recurso   = mysqli_connect("localhost", "root", "", "faceta");
        if (mysqli_connect_error())
        {
            printf("Error conectando a la base de datos: %s\n", mysqli_connect_error());
            exit();
        }
        mysqli_query($recurso, "INSERT INTO usuario (codigo, activo, usuario, clave, admin, nombre, apellidos, domicilio, poblacion, provincia, cp, telefono, tarjeta) VALUES ('{$codigo}', '{$activo}', '{$usuario}', '{$clave}', '{$admin}', '{$nombre}', '{$apellidos}', '{$domicilio}', '{$poblacion}', '{$provincia}', '{$cp}', '{$telefono}', '')");
        header('Location: accedido.php');
        mysqli_close($recurso);
?>

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
?>