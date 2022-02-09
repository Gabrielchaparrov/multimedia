<?php
session_unset();
session_destroy();
$_SESSION['validado'] = false;
header('Location: index.php');
?>