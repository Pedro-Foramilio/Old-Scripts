package ProjetoDuvida;

public abstract class Duvida {
    private String texto;

    public Duvida(String texto) {
        this.texto = texto;
    }

    @Override
    public String toString() {
        return "Duvida = " + this.texto;
    }
}
