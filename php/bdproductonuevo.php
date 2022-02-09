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
        mysqli_query($recurso, "INSERT INTO productos (codigo, activo, descripcion, precio, existencias, imagen, imagen2) VALUES ('{$codigo}', '{$activo}', '{$descripcion}', '{$precio}', '{$existencias}', '{$img}', '{$img2}')");
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