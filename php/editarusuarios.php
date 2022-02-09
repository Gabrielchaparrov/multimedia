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
        if ($resultado = mysqli_query($recurso, "SELECT * FROM usuario"))
        {
            printf("La selección devolvió %d filas.\n", mysqli_num_rows($resultado));
?>
     
    <table style="width: 50%">
        <tr>
            <td>Código</td>
            <td>Activo</td>
            <td>Usuario</td>
            <td>Clave</td>
            <td>Admin</td>
            <td>Nombre</td>
            <td>Apellidos</td>
            <td>Domicilio</td>
            <td>Población</td>
            <td>Provincia</td>
            <td>Código Postal</td>
            <td>Teléfono</td>
            <td>¿BORRAR? 1=SI</td>
            <td></td>
        </tr>
      
<?php
            while ($fila = mysqli_fetch_row($resultado))
            {
?>
       
        <form method="post" action="editarbd.php">
            <tr>
                <td><input name="codigo" value= <?php echo $fila[0]; ?>></td>
                <td><input name="activo" value= <?php echo $fila[1]; ?>></td>
                <td><input name="usuario" value= <?php echo $fila[2]; ?>></td>
                <td><input name="clave" value= <?php echo $fila[3]; ?>></td>
                <td><input name="admin" value= <?php echo $fila[4]; ?>></td>
                <td><input name="nombre" value= '<?php echo $fila[5]; ?>'></td>
                <td><input name="apellidos" value= '<?php echo $fila[6]; ?>'></td>
                <td><input name="domicilio" value= '<?php echo $fila[7]; ?>'></td>
                <td><input name="poblacion" value= '<?php echo $fila[8]; ?>'></td>
                <td><input name="provincia" value= '<?php echo $fila[9]; ?>'></td>
                <td><input name="cp" value= <?php echo $fila[10]; ?>></td>
                <td><input name="telefono" value= <?php echo $fila[11]; ?>></td>
                <td><input name="borrar" placeholder="1 para borrar"></td>
                <td><input type="submit" value="EditarUsuario"></td>
            </tr>
        </form>
        
        <?php
            }
?>
       
        <form method="post" action="bdusuarionuevo.php">
            <tr>
                <td><input name="codigo" placeholder="No repetido"></td>
                <td><input name="activo"></td>
                <td><input name="usuario" placeholder="No repetido"></td>
                <td><input name="clave"></td>
                <td><input name="admin"></td>
                <td><input name="nombre"></td>
                <td><input name="apellidos"></td>
                <td><input name="domicilio"></td>
                <td><input name="poblacion"></td>
                <td><input name="provincia"></td>
                <td><input name="cp"></td>
                <td><input name="telefono"></td>
                <td></td>
                <td><input type="submit" value="AñadirUsuario"></td>
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