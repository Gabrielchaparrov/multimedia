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
        $codigopedido   = $_REQUEST['codigopedido'];
        $codproducto    = $_REQUEST['codigoproducto'];
        $unidades       = $_REQUEST['unidades'];
        $preciounitario = $_REQUEST['preciounitario'];
        $recurso        = mysqli_connect("localhost", "root", "", "faceta");
        if (mysqli_connect_error())
        {
            printf("Error conectando a la base de datos: %s\n", mysqli_connect_error());
            exit();
        }
        mysqli_query($recurso, "UPDATE detalle SET CodigoPedido = '{$codigopedido}', CodigoProducto = '{$codproducto}', Unidades = '{$unidades}', PrecioUnitario = '{$preciounitario}' WHERE CodigoPedido = '{$codigopedido}'");
        echo "UPDATE detalle SET CodigoPedido = '{$codigopedido}', CodigoProducto = '{$codproducto}', Unidades = '{$unidades}', PrecioUnitario = '{$preciounitario}' WHERE CodigoPedido = '{$codigopedido}'";
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