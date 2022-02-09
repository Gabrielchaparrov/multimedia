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
        $comprador = $_REQUEST['comprador'];
        $date      = $_REQUEST['fecha'];
        $importe   = $_REQUEST['importe'];
        $estado    = $_REQUEST['estado'];
        $recurso   = mysqli_connect("localhost", "root", "", "faceta");
        if (mysqli_connect_error())
        {
            printf("Error conectando a la base de datos: %s\n", mysqli_connect_error());
            exit();
        }
        $aux = mysqli_query($recurso, "UPDATE pedidos SET Codigo = '{$codigo}', Comprador = '{$comprador}', Fecha = '{$date}', Importe = '{$importe}', Estado = '{$estado}' WHERE Codigo = '{$codigo}'");
        echo "UPDATE pedidos SET Codigo = '{$codigo}', Comprador = '{$comprador}', Fecha = '{$date}', Importe = '{$importe}', Estado = '{$estado}' WHERE Codigo = '{$codigo}'";
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