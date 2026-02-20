public class Prestamo {
    Usuario usuario;
    Libro libro;
    boolean activo;

    public Prestamo(Usuario usuario, Libro libro) {
        this.usuario = usuario;
        this.libro = libro;
        this.activo = true;
    }
}
