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
        $recurso = mysqli_connect("localhost", "root", "", "faceta");
        if (mysqli_connect_error())
        {
            printf("Error conectando a la base de datos: %s\n", mysqli_connect_error());
            exit();
        }
        if ($resultado = mysqli_query($recurso, "SELECT * FROM pedidos"))
        {
            printf("La selección devolvió %d filas.\n", mysqli_num_rows($resultado));
            while ($fila = mysqli_fetch_row($resultado))
            {
?>

        
        <table>
            <br><hr><br>
        <tr>
            <td>Código</td>
            <td>Comprador</td>
            <td>Fecha</td>
            <td>Importe</td>
            <td>Estado</td>
            <td></td>
        </tr>
        
        <form method="post" action="bdpedido.php">
            <tr>
                <td><input name="codigo" value= <?php echo $fila[0]; ?>></td>
                <td><input name="comprador" value= <?php echo $fila[1]; ?>></td>
                <td><input type="date" name="fecha" value= <?php echo $fila[2]; ?>></td>
                <td><input name="importe" value= <?php echo $fila[3]; ?>></td>
                <td><input name="estado" value= <?php echo $fila[4]; ?>></td>
                <td><input type="submit" value="EditarPedido"></td>
            </tr>
        </form>
        
        <?php
                if ($resultado2 = mysqli_query($recurso, "SELECT * FROM detalle"))
                {
                    while ($fila2 = mysqli_fetch_row($resultado2))
                    {
                        if ($fila2[0] == $fila[0])
                        {
?>

        <tr>
            <td>Código Pedido</td>
            <td>Código Producto</td>
            <td>Unidades</td>
            <td>Precio Unitario</td>
            <td></td>
            <td></td>
        </tr>
        
        <form method="post" action="bddetalle.php">
            <tr>
                <td><input name="codigopedido" value= <?php echo $fila2[0]; ?>></td>
                <td><input name="codigoproducto" value= <?php echo $fila2[1]; ?>></td>
                <td><input name="unidades" value= <?php echo $fila2[2]; ?>></td>
                <td><input name="preciounitario" value= <?php echo $fila2[3]; ?>></td>
                <td></td>
                <td><input type="submit" value="EditarDetalle"></td>
            </tr>
        </form>

        
        <?php
                        }
                    }
                }
            }
?>
        </table><br><br> 

    <form method="post" action="pedidosfecha.php">
        <input name="fecha" type="date">
        <input type="submit" value="FILTRAR POR FECHA">
    </form>

    <form method="post" action="pedidosusuario.php">
        <input name="user">
        <input type="submit" value="FILTRAR POR USUARIO">
    </form>

    <form method="post" action="pedidosproducto.php">
        <input name="prod">
        <input type="submit" value="FILTRAR POR PRODUCTO">
    </form>

    <form method="post" action="accedido.php">
        <input type="submit" value="Volver">
    </form>
    <?php
        }
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