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
        if ($resultado = mysqli_query($recurso, "SELECT * FROM productos"))
        {
            printf("La selección devolvió %d filas.\n", mysqli_num_rows($resultado));
?>
     
    <table>
        <tr>
            <td>Código</td>
            <td>Activo</td>
            <td>Descripción</td>
            <td>Precio</td>
            <td>Existencias</td>
            <td>Imagen</td>
            <td>Imagen Hover</td>
            <td>¿BORRAR? 1=SI</td>
            <td></td>
        </tr>
      
<?php
            while ($fila = mysqli_fetch_row($resultado))
            {
?>
       
        <form method="post" action="bdproducto.php">
            <tr>
                <td><input name="codigo" value= <?php echo $fila[0]; ?>></td>
                <td><input name="activo" value= <?php echo $fila[1]; ?>></td>
                <td><input name="descripcion" value='<?php echo $fila[2]; ?>'></td>
                <td><input name="precio" value= <?php echo $fila[3]; ?>></td>
                <td><input name="existencias" value= <?php echo $fila[4]; ?>></td>
                <td><input name="img" value= <?php echo $fila[5]; ?>></td>
                <td><input name="img2" value= <?php echo $fila[6]; ?>></td>
                <td><input name="borrar" placeholder="1 para borrar"></td>
                <td><input type="submit" value="EditarProducto"></td>
            </tr>
        </form>
        
        <?php
            }
?>
       
        <form method="post" action="bdproductonuevo.php">
            <tr>
                <td><input name="codigo" placeholder="No repetido"></td>
                <td><input name="activo" ></td>
                <td><input name="descripcion" ></td>
                <td><input name="precio" ></td>
                <td><input name="existencias" ></td>
                <td><input name="img" ></td>
                <td><input name="img2" ></td>
                 <td></td>
                <td><input type="submit" value="AñadirProducto"></td>
            </tr>
        </form>
        
    </table>  

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