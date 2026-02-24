public class Usuario {

    private int id;
    private String nombre;
    private int librosPrestados;
    private int maxLibros = 3;

    public Usuario(int id, String nombre) {
        setId(id);
        setNombre(nombre);
        this.librosPrestados = 0;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        if (id > 0) {
            this.id = id;
        } else {
            System.out.println("ID inválido. Se asigna 1.");
            this.id = 1;
        }
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        if (nombre != null && !nombre.trim().isEmpty()) {
            this.nombre = nombre;
        } else {
            System.out.println("Nombre inválido. Se asigna 'Usuario'.");
            this.nombre = "Usuario";
        }
    }

    public int getLibrosPrestados() {
        return librosPrestados;
    }

    public boolean puedePedirPrestado() {
        return librosPrestados < maxLibros;
    }

    public void incrementarPrestamos() {
        if (puedePedirPrestado()) {
            librosPrestados++;
        } else {
            System.out.println("Ha alcanzado el máximo de libros.");
        }
    }

    public void devolverLibro() {
        if (librosPrestados > 0) {
            librosPrestados--;
        }
    }

    @Override
    public String toString() {
        return id + " - " + nombre + " (Prestados: " + librosPrestados + ")";
    }
}