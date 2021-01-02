package cartoes;

public class CartaoLimitado extends CartaoCredito{
    @Override
    public boolean pagarComCredito(double valor) {
        if (valor <= 200.00 && (this.verificarExtrato() + valor) <=200){
            return super.pagarComCredito(valor);
        }
        else {
            return false;
        }
        
    }
}
