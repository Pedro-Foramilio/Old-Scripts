package automotores;

public class Carro extends Veiculo{
    private int numeroPortas;

    public void setNumeroPortas(int n) {
        this.numeroPortas = n;
    }

    public int getNumeroPortas() {
        return numeroPortas;
    }

    @Override
    public String getTipo() {
        return "Carro modelo " + this.tipo;
    }
}
