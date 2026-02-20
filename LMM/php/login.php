<?php
session_start();
include("conexion.php");

if($_SERVER["REQUEST_METHOD"] == "POST"){

    $email = $_POST["email"];
    $password = $_POST["password"];

    $sql = "SELECT * FROM usuarios WHERE email='$email'";
    $resultado = $conexion->query($sql);

    if($resultado->num_rows == 1){
        $usuario = $resultado->fetch_assoc();

        if(password_verify($password, $usuario["password"])){
            $_SESSION["usuario"] = $usuario["email"];
            echo "Login correcto";
        } else {
            echo "Contraseña incorrecta";
        }
    } else {
        echo "Usuario no existe";
    }
}
?>

<form method="POST">
    Email: <input type="email" name="email"><br>
    Password: <input type="password" name="password"><br>
    <button type="submit">Login</button>
</form>
