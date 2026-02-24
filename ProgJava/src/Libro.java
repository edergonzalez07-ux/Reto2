public class Libro {

    private int id;
    private String titulo;
    private Autor autor;

    public Libro(int id, String titulo, Autor autor) {
        setId(id);
        setTitulo(titulo);
        setAutor(autor);
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

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        if (titulo != null && !titulo.trim().isEmpty()) {
            this.titulo = titulo;
        } else {
            System.out.println("Título inválido. Se asigna 'Sin título'.");
            this.titulo = "Sin título";
        }
    }

    public Autor getAutor() {
        return autor;
    }

    public void setAutor(Autor autor) {
        if (autor != null) {
            this.autor = autor;
        } else {
            System.out.println("Autor inválido.");
        }
    }

    @Override
    public String toString() {
        return id + " - " + titulo + " - " + autor.getNombre();
    }
}