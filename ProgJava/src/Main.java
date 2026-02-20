public class Main {
    public static void main(String[] args) {

        // USUARIOS
        Usuario[] usuarios = new Usuario[5];
        usuarios[0] = new Usuario(1, "Ander");
        usuarios[1] = new Usuario(2, "Eder");

        // Crear autores
        Autor[] autores = new Autor[10]; // dejamos hueco para altas
        autores[0] = new Autor(1, "Gabriel Garcia Márquez");
        autores[1] = new Autor(2, "J.K. Rowling");
        autores[2] = new Autor(3, "Federico García Lorca");
        autores[3] = new Autor(4, "George R.R. Martin");
        autores[4] = new Autor(5, "HP Lovecraft");

        // Crear libros
        Libro[] libros = new Libro[30]; // dejamos hueco para altas
        libros[0] = new Libro(1, "100 Años de Soledad", autores[0]);
        libros[1] = new Libro(2, "Harry Potter y la Piedra Filosofal", autores[1]);
        libros[2] = new Libro(3, "La casa de Bernarda Alba", autores[2]);
        libros[3] = new Libro(4, "Canciones de Hielo y Fuego", autores[3]);
        libros[4] = new Libro(5, "La llamada de Chuthulu", autores[4]);
        
        // ALTA DE AUTOR
        autores[5] = new Autor(6, "Edgar Allan Poe");
        
        // ALTA DE LIBRO
        libros[5] = new Libro(21, "El cuervo", autores[5]);
    
        // BAJA DE LIBRO (eliminar libro con id 5)        
        for (int i = 0; i < libros.length; i++) {
            if (libros[i] != null && libros[i].id == 5) {
                libros[i] = null; 
            }
        }
        
        // MODIFICAR LIBRO (cambiar título y precio del libro 3)        
        for (int i = 0; i < libros.length; i++) {
            if (libros[i] != null && libros[i].id == 3) {
                libros[i].titulo = "Bodas de sangre";
            }
        }

        // MODIFICAR AUTOR (cambiar nombre del autor 2)        
        for (int i = 0; i < autores.length; i++) {
            if (autores[i] != null && autores[i].id == 2) {
                autores[i].nombre = "Pepe Viyuela";
            }
        }
        
        // LISTADO DE LIBROS        
        System.out.println("LISTADO DE LIBROS:");
        for (int i = 0; i < libros.length; i++) {
            if (libros[i] != null) {
                System.out.println(
                        libros[i].id + " - " +
                        libros[i].titulo + " - " +
                        libros[i].autor.nombre
                );
            }
        }

        // PRESTAMOS
        Prestamo[] prestamos = new Prestamo[20];

        // DEVOLVER PRÉSTAMO
        prestamos[0].activo = false;
        usuarios[0].librosPrestados--;
        
        // MÁXIMO DE 3 
        if (usuarios[0].librosPrestados < 3) {
            prestamos[0] = new Prestamo(usuarios[0], libros[0]);
            usuarios[0].librosPrestados++;
            System.out.println("Préstamo realizado: " + usuarios[0].nombre + " -> " + libros[0].titulo);
        }

    }
}
