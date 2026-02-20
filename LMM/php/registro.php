<?php
include("conexion.php");

if($_SERVER["REQUEST_METHOD"] == "POST"){

    $email = $_POST["email"];
    $password = password_hash($_POST["password"], PASSWORD_DEFAULT);

    $sql = "INSERT INTO usuarios (email, password) VALUES ('$email', '$password')";
    $conexion->query($sql);

    echo "Usuario creado correctamente";
}
?>

<form method="POST">
    Email: <input type="email" name="email" required><br>
    Password: <input type="password" name="password" required><br>
    <button type="submit">Registrarse</button>
</form>
