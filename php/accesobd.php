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
        else
        {
            printf("ENTRA");
        }
        if ($resultado = mysqli_query($recurso, "SELECT * FROM usuario"))
        {
            printf("La selección devolvió %d filas.\n", mysqli_num_rows($resultado));
            while ($fila = mysqli_fetch_row($resultado))
            {
                echo '<br/>';
                printf("codigo=%d, activo=%d, usuario=%s, clave=%s, admin=%d, nombre=%s, apellidos=%s", $fila[0], $fila[1], $fila[2], $fila[3], $fila[4], $fila[5], $fila[6]);
            }
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