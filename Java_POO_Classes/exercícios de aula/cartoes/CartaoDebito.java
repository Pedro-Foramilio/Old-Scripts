package cartoes;

public class CartaoDebito {
    //private String titular;
    private double saldo = 0.0;
/*
    public void setTitular(String nome) {
        this.titular = nome;
    }
*/
    
    public void adicionarSaldo(double valor) {
        this.saldo += valor;
    }
    public double verificarSaldoDebito() {
        return saldo;
    }

    public boolean pagarComDebito(double valor) {
        if (validaOperacao(valor)) {
            this.saldo -= valor;
            return true;
        }
        else {
            return false;
        }
    }

    protected boolean validaOperacao(double valor) {
        if (valor <= 0){
            return false;
        } 

        if (this.saldo < valor) {
            return false;
        }
        
        return true; //se valor > 0 e saldo > valor
    }
    
}
