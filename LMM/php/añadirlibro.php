<?php
session_start();
if(!isset($_SESSION["usuario"])){
    header("Location: ../index.php");
    exit();
}

include("conexion.php");

if($_SERVER["REQUEST_METHOD"] == "POST"){
    
    $titulo = $_POST["titulo"];
    $autor = $_POST["autor"];
    $descripcion = $_POST["descripcion"];
    
    $stmt = $conexion->prepare("INSERT INTO libros (titulo, autor, descripcion) VALUES (?, ?, ?)");
    $stmt->bind_param("sss", $titulo, $autor, $descripcion);
    
    if($stmt->execute()){
        echo "Libro añadido correctamente";
    } else {
        echo "Error: " . $conexion->error;
    }
    
    $stmt->close();
}
?>
