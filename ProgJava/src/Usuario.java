public class Usuario {
    int id;
    String nombre;
    int librosPrestados; // cuántos libros tiene actualmente

    public Usuario(int id, String nombre) {
        this.id = id;
        this.nombre = nombre;
        this.librosPrestados = 0;
    }
}
