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
        $codigo      = $_REQUEST['codigo'];
        $activo      = $_REQUEST['activo'];
        $descripcion = $_REQUEST['descripcion'];
        $precio      = $_REQUEST['precio'];
        $existencias = $_REQUEST['existencias'];
        $img         = $_REQUEST['img'];
        $img2        = $_REQUEST['img2'];
        $recurso     = mysqli_connect("localhost", "root", "", "faceta");
        if (mysqli_connect_error())
        {
            printf("Error conectando a la base de datos: %s\n", mysqli_connect_error());
            exit();
        }
        if ($_REQUEST['borrar'] != 1)
        {
            mysqli_query($recurso, "UPDATE productos SET codigo = '{$codigo}', activo = '{$activo}', descripcion = '{$descripcion}', precio = '{$precio}', existencias = '{$existencias}', imagen = '{$img}', imagen2 = '{$img2}' WHERE codigo = '{$codigo}'");
        }
        else
        {
            mysqli_query($recurso, "DELETE FROM productos WHERE codigo = '{$codigo}'");
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