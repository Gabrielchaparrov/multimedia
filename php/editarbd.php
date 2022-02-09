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
        if ($_REQUEST['borrar'] != 1)
        {
            mysqli_query($recurso, "UPDATE usuario SET codigo = '{$codigo}', activo = '{$activo}', usuario = '{$usuario}', clave = '{$clave}', admin = '{$admin}', nombre = '{$nombre}', apellidos = '{$apellidos}', domicilio = '{$domicilio}', poblacion = '{$poblacion}', provincia = '{$provincia}', cp = '{$cp}', telefono = '{$telefono}' WHERE codigo = '{$codigo}'");
        }
        else
        {
            mysqli_query($recurso, "DELETE FROM usuario WHERE codigo = '{$codigo}'");
        }
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