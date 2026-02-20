<?php
session_start();
session_destroy();
header("Location: ../index.php"); // <--- CAMBIADO a index.php
exit();
?>