<?php
session_start();
include("php/conexion.php");

if(!isset($_SESSION["usuario"])){
    die("Debes iniciar sesión");
}

if($_SERVER["REQUEST_METHOD"] == "POST"){

    $nueva = password_hash($_POST["nueva_password"], PASSWORD_DEFAULT);
    $email = $_SESSION["usuario"];

    $sql = "UPDATE usuarios SET password='$nueva' WHERE email='$email'";
    $conexion->query($sql);

    echo "Contraseña actualizada";
}
?>

<form method="POST">
    Nueva contraseña: <input type="password" name="nueva_password"><br>
    <button type="submit">Cambiar</button>
</form>
