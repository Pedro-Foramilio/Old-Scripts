package automotores;

public class Veiculo {
    protected String tipo;

    public String getTipo() {
        return "Veiculo generico modelo " + this.tipo;
    }

    public void setModelo(String modelo) {
        this.tipo = modelo;
    }
}
