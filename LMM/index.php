<?php
session_start();

// Procesar login si viene del formulario
if($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['email'])){
    include("php/conexion.php");
    
    $email = $conexion->real_escape_string($_POST['email']);
    $password = $_POST['password'];
    
    $sql = "SELECT * FROM usuarios WHERE email='$email'";
    $resultado = $conexion->query($sql);
    
    if($resultado->num_rows == 1){
        $usuario = $resultado->fetch_assoc();
        if(password_verify($password, $usuario['password'])){
            $_SESSION['usuario'] = $usuario['email'];
            header("Location: index.php");
            exit;
        } else {
            $error = "Contraseña incorrecta";
        }
    } else {
        $error = "Usuario no existe";
    }
}
?>
<!doctype html>
<html lang="es">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Biblioteca de Muskiz — Inicio</title>
  <link rel="icon" href="img/logo_reto1-removebg-preview.png" />
  <link rel="stylesheet" href="css/estilos.css" />
</head>
<body>

<?php if(!isset($_SESSION["usuario"])): ?>

<!-- ================= LOGIN MEJORADO ================= -->
<section class="hero" style="text-align:center; padding:50px 20px;">
    <h2>Bienvenido a la Biblioteca de Muskiz</h2>
    <p>Inicia sesión para acceder a todo el contenido</p>
    
    <?php if(isset($error)): ?>
        <div class="error-msg">
            <?php echo $error; ?>
        </div>
    <?php endif; ?>

    <div class="login-form">
        <form method="POST">
            <label for="email">Email:</label>
            <input type="email" id="email" name="email" placeholder="tu@email.com" required>
            
            <label for="password">Contraseña:</label>
            <input type="password" id="password" name="password" placeholder="••••••••" required>
            
            <button type="submit">Entrar</button>
        </form>
        
        <p style="margin-top: 20px;">
            ¿No tienes cuenta? 
            <a href="php/registro.php" style="color: #4CAF50; font-weight: bold;">Regístrate aquí</a>
        </p>
    </div>
</section>

<?php else: ?>

<!-- ================= WEB PRINCIPAL ================= -->
<header>
  <div class="header-inner">
    <div class="brand">
      <span class="logo">
        <img src="img/logo_reto1-removebg-preview.png" width="60">
      </span>
      <div>
        <h1>Biblioteca de Muskiz</h1>
      </div>
    </div>
    <nav class="color">
      <a href="index.php" class="active">Inicio</a>
      <span></span>
      <a href="about.html">Quiénes Somos</a>
      <span></span>
      <a href="catalog.html">Catálogo</a>
      <span></span>
      <a href="visit.html">Visítanos</a>
      <span></span>
      <a href="formulario.html">Contacto</a>
      <span></span>
      <a href="php/logout.php">Cerrar sesión</a>
    </nav>
  </div>
</header>

<?php include("php/contenidohome.php");?>

<?php endif; ?>

<script>
document.addEventListener("DOMContentLoaded", function () {
    document.body.classList.add("page-loaded");
});
</script>
</body>
</html>