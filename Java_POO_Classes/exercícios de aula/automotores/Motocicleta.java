package automotores;

public class Motocicleta extends Veiculo{
    private boolean temCarro;

    public void setTemCarroLateral(boolean var) {
        this.temCarro = var;
    }

    public boolean getTemCarroLateral() {
        return this.temCarro;
    }

    @Override
    public String getTipo() {
        return "Motocicleta modelo " + this.tipo;
    }
}
