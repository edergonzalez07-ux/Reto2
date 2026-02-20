<?php
session_start();

if(!isset($_SESSION["usuario"])){
    header("Location: index.php");
    exit();
}

include("php/conexion.php");

$resultado = $conexion->query("SELECT * FROM libros");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Biblioteca</title>
</head>
<body>

<h1>Bienvenido <?php echo $_SESSION["usuario"]; ?></h1>

<a href="logout.php">Cerrar sesión</a>

<h2>Lista de libros</h2>

<?php while($libro = $resultado->fetch_assoc()): ?>
    <div style="border:1px solid #ccc; margin:10px; padding:10px;">
        <h3><?php echo $libro['titulo']; ?></h3>
        <p><?php echo $libro['autor']; ?></p>
        <p><?php echo $libro['descripcion']; ?></p>
    </div>
<?php endwhile; ?>

</body>
</html>
