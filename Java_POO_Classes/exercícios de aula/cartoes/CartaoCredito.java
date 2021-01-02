package cartoes;

public class CartaoCredito extends CartaoDebito {
    private double divida = 0.0;

    public boolean pagarComCredito(double valor) {
        this.divida += valor;
        return true;
    }

    public void quitarCredito(double valor) {
        this.pagarComDebito(valor);
        this.divida -= valor;
    }

    public double verificarExtrato() {
        return this.divida;
    }

}
