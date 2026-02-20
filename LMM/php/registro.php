<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

include 'conexion.php';

if ($conexion->connect_error) {
    die("Error de conexión: " . $conexion->connect_error);
}

$mensaje = "";
$tipo = "";

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['registrar'])) {
    $email = trim($_POST['email']);
    $password = $_POST['password'];
    
    if (empty($email) || empty($password)) {
        $mensaje = "Todos los campos son obligatorios";
        $tipo = "error";
    } elseif (strlen($password) < 6) {
        $mensaje = "La contraseña debe tener al menos 6 caracteres";
        $tipo = "error";
    } else {
        $email = $conexion->real_escape_string($email);
        $password_hash = password_hash($password, PASSWORD_DEFAULT);
        
        $check = $conexion->query("SELECT id FROM usuarios WHERE email = '$email'");
        
        if ($check && $check->num_rows > 0) {
            $mensaje = "Este email ya está registrado";
            $tipo = "error";
        } else {
            $sql = "INSERT INTO usuarios (email, password) VALUES ('$email', '$password_hash')";
            
            if ($conexion->query($sql)) {
                $mensaje = "Registro exitoso. <a href='../index.php'>Inicia sesión</a>";
                $tipo = "exito";
            } else {
                $mensaje = "Error: " . $conexion->error;
                $tipo = "error";
            }
        }
    }
}
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Registro</title>
    <style>
        body { font-family: Arial; background: #f0f2f5; display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; }
        .container { background: white; padding: 30px; border-radius: 8px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); width: 350px; }
        h1 { text-align: center; color: #333; }
        label { display: block; margin: 10px 0 5px; color: #555; }
        input { width: 100%; padding: 8px; margin-bottom: 15px; border: 1px solid #ddd; border-radius: 4px; box-sizing: border-box; }
        button { width: 100%; padding: 10px; background: #4CAF50; color: white; border: none; border-radius: 4px; cursor: pointer; }
        button:hover { background: #45a049; }
        .error { background: #f8d7da; color: #721c24; padding: 10px; border-radius: 4px; margin-bottom: 15px; }
        .exito { background: #d4edda; color: #155724; padding: 10px; border-radius: 4px; margin-bottom: 15px; }
        .link { text-align: center; margin-top: 15px; }
        .link a { color: #4CAF50; text-decoration: none; }
    </style>
</head>
<body>
    <div class="container">
        <h1>Registro</h1>
        
        <?php if($mensaje): ?>
            <div class="<?php echo $tipo; ?>"><?php echo $mensaje; ?></div>
        <?php endif; ?>
        
        <form method="POST">
            <label>Email:</label>
            <input type="email" name="email" required>
            
            <label>Contraseña:</label>
            <input type="password" name="password" required minlength="6">
            
            <button type="submit" name="registrar">Registrarse</button>
        </form>
        
        <div class="link">
            <a href="../index.php">Volver al inicio</a>
        </div>
    </div>
</body>
</html>