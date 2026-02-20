<?php
include("php/conexion.php");

if($_SERVER["REQUEST_METHOD"] == "POST"){

    $titulo = $_POST["titulo"];
    $autor = $_POST["autor"];
    $descripcion = $_POST["descripcion"];

    $sql = "INSERT INTO libros (titulo, autor, descripcion) 
            VALUES ('$titulo', '$autor', '$descripcion')";

    $conexion->query($sql);

    echo "Libro añadido correctamente";
}
?>

<form method="POST">
    Título: <input type="text" name="titulo"><br>
    Autor: <input type="text" name="autor"><br>
    Descripción: <textarea name="descripcion"></textarea><br>
    <button type="submit">Añadir libro</button>
</form>
