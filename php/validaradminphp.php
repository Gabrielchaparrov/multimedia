<?php
session_start();
if (isset($_REQUEST['usuario']) && isset($_REQUEST['clave']))
{
    $user       = $_REQUEST['usuario'];
    $contrasena = $_REQUEST['clave'];
    $recurso    = mysqli_connect("localhost", "root", "", "faceta");
    if (mysqli_connect_error())
    {
        printf("Error conectando a la base de datos: %s\n", mysqli_connect_error());
        exit();
    }
    if ($resultado = mysqli_query($recurso, "SELECT usuario, clave, admin, codigo FROM usuario"))
    {
        while ($fila = mysqli_fetch_row($resultado))
        {
            if ($user == $fila[0] && $contrasena == $fila[1])
            {
                if ($fila[2] == 1)
                {
                    $correcto = true;
                    $_SESSION['userid'] = $fila[3];
                }
            }
        }
    }
    if ($correcto == true)
    {
        $_SESSION['validado'] = true;
        header('Location: accedido.php');
    }
    else
    {
        $_SESSION['validado'] = false;
        header('Location: index.php');
    }
}
else
{
    header('Location: index.php');
}
mysqli_close($recurso);
?>