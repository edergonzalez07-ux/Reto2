<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

$conexion = new mysqli("localhost", "root", "", "incidencias");

if ($conexion->connect_error) {
    die("Error de conexión: " . $conexion->connect_error);
}

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
        echo "Error al subir la imagen.";
        exit;
    }
}



$sql = "INSERT INTO incidencias 
(nombre, email, tipo, tipo_otro, isbn, observaciones, mensaje, foto)
VALUES 
('$nombre', '$email', '$tipo', '$tipo_otro', '$isbn', '$observaciones', '$mensaje', '$foto_nombre')";

if ($conexion->query($sql) === TRUE) {
    echo "Incidencia enviada correctamente.";
} else {
    echo "Error en la consulta: " . $conexion->error;
}

$conexion->close();
?>
