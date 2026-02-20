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

<!-- ================= LOGIN ================= -->

<section class="hero" style="text-align:center; padding:100px 20px;">
    <h2>Iniciar sesión</h2>

    <?php if(isset($error)) echo "<p style='color:red;'>$error</p>"; ?>

    <form method="POST" style="margin-top:20px;">
        <input type="email" name="email" placeholder="Email" required><br><br>
        <input type="password" name="password" placeholder="Contraseña" required><br><br>
        <button type="submit">Entrar</button>
    </form>

    <p style="margin-top:20px;">
        <a href="php/registro.php">Crear cuenta</a>
    </p>
</section>

<?php else: ?>

<!-- ================= TU WEB ORIGINAL ================= -->

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

<!-- TODO TU MAIN EXACTAMENTE IGUAL -->
<?php include("php/contenidohome.php");?>


<?php endif; ?>

<script>
document.addEventListener("DOMContentLoaded", function () {
    document.body.classList.add("page-loaded");
});
</script>

</body>
</html>
