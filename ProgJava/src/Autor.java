public class Autor {

    private int id;
    private String nombre;

    public Autor(int id, String nombre) {
        setId(id);
        setNombre(nombre);
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
            System.out.println("Nombre inválido. Se asigna 'Desconocido'.");
            this.nombre = "Desconocido";
        }
    }

    @Override
    public String toString() {
        return id + " - " + nombre;
    }
}