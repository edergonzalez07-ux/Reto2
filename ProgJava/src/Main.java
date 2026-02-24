public class Main {

    public static void main(String[] args) {

        // USUARIOS
        Usuario[] usuarios = new Usuario[5];
        usuarios[0] = new Usuario(1, "Ander");
        usuarios[1] = new Usuario(2, "Eder");
        usuarios[2] = new Usuario(3, "Aitor Martín");
        usuarios[3] = new Usuario(4, "Aitor García");
        usuarios[4] = new Usuario(5, "Marcos");

        // AUTORES
        Autor[] autores = new Autor[10];
        autores[0] = new Autor(1, "Gabriel Garcia Márquez");
        autores[1] = new Autor(2, "J.K. Rowling");
        autores[2] = new Autor(3, "Federico García Lorca");
        autores[3] = new Autor(4, "George R.R. Martin");
        autores[4] = new Autor(5, "HP Lovecraft");

        // LIBROS
        Libro[] libros = new Libro[30];
        libros[0] = new Libro(1, "100 Años de Soledad", autores[0]);
        libros[1] = new Libro(2, "Harry Potter", autores[1]);
        libros[2] = new Libro(3, "La casa de Bernarda Alba", autores[2]);
        libros[3] = new Libro(4, "Juego de Tronos", autores[3]);
        libros[4] = new Libro(5, "La llamada de Cthulhu", autores[4]);

        // BAJA DE LIBRO (id 5)
        for (int i = 0; i < libros.length; i++) {
            if (libros[i] != null && libros[i].getId() == 5) {
                libros[i] = null;
            }
        }

        // MODIFICAR LIBRO (id 3)
        for (int i = 0; i < libros.length; i++) {
            if (libros[i] != null && libros[i].getId() == 3) {
                libros[i].setTitulo("Bodas de sangre");
            }
        }

        // LISTADO DE LIBROS
        System.out.println("LISTADO DE LIBROS:");
        for (int i = 0; i < libros.length; i++) {
            if (libros[i] != null) {
                System.out.println(libros[i]);
            }
        }

        // PRÉSTAMO
        Prestamo[] prestamos = new Prestamo[20];

        if (usuarios[0].puedePedirPrestado()) {
            prestamos[0] = new Prestamo(usuarios[0], libros[0]);
            usuarios[0].incrementarPrestamos();
            System.out.println("Préstamo realizado: " + prestamos[0]);
        }

        // DEVOLUCIÓN
        prestamos[0].devolver();
        System.out.println("Después de devolver: " + prestamos[0]);
    }
}