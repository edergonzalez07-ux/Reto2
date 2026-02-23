<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

// CORREGIDO: Conectamos a la base de datos "reto2" (no a "incidencias")
$conexion = new mysqli("localhost", "root", "", "reto2");

if ($conexion->connect_error) {
    die("Error de conexión: " . $conexion->connect_error);
}

$conexion->set_charset("utf8");

$nombre = $_POST['nombre'] ?? '';
$email = $_POST['email'] ?? '';
$tipo = $_POST['tipo'] ?? '';
$tipo_otro = $_POST['tipo_otro'] ?? '';
$isbn = $_POST['isbn'] ?? '';
$observaciones = $_POST['observaciones'] ?? '';
$mensaje = $_POST['mensaje'] ?? '';
$foto_nombre = '';

if(isset($_FILES['foto']) && $_FILES['foto']['error'] == 0){
    
    $directorio = "../fotos/";

    if(!is_dir($directorio)){
        mkdir($directorio, 0777, true);
    }

    $foto_nombre = time() . "_" . basename($_FILES["foto"]["name"]);
    $ruta_completa = $directorio . $foto_nombre;

    if(!move_uploaded_file($_FILES["foto"]["tmp_name"], $ruta_completa)){
        die("Error al subir la imagen.");
    }
}

// Escapar los valores para evitar inyección SQL
$nombre = $conexion->real_escape_string($nombre);
$email = $conexion->real_escape_string($email);
$tipo = $conexion->real_escape_string($tipo);
$tipo_otro = $conexion->real_escape_string($tipo_otro);
$isbn = $conexion->real_escape_string($isbn);
$observaciones = $conexion->real_escape_string($observaciones);
$mensaje = $conexion->real_escape_string($mensaje);
$foto_nombre = $conexion->real_escape_string($foto_nombre);

$fecha = date('Y-m-d H:i:s');

// La tabla se llama "incidencias" dentro de la BD "reto2"
$sql = "INSERT INTO incidencias 
(nombre, email, tipo, tipo_otro, isbn, observaciones, mensaje, foto, fecha)
VALUES 
('$nombre', '$email', '$tipo', '$tipo_otro', '$isbn', '$observaciones', '$mensaje', '$foto_nombre', '$fecha')";

if ($conexion->query($sql) === TRUE) {
    echo "Incidencia enviada correctamente.";
    // Redireccionar (opcional)
    // header("Location: exito.html");
    // exit();
} else {
    echo "Error en la consulta: " . $conexion->error;
}

$conexion->close();
?>