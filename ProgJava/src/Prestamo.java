public class Prestamo {

    private Usuario usuario;
    private Libro libro;
    private boolean activo;

    public Prestamo(Usuario usuario, Libro libro) {
        if (usuario != null && libro != null) {
            this.usuario = usuario;
            this.libro = libro;
            this.activo = true;
        } else {
            System.out.println("No se pudo crear el préstamo.");
            this.activo = false;
        }
    }

    public void devolver() {
        if (activo) {
            activo = false;
            usuario.devolverLibro();
        }
    }

    public boolean isActivo() {
        return activo;
    }

    @Override
    public String toString() {
        if (usuario != null && libro != null) {
            return usuario.getNombre() + " -> " + libro.getTitulo() +
                    (activo ? " (Activo)" : " (Devuelto)");
        }
        return "Préstamo inválido";
    }
}