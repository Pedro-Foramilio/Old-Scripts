package ProjetoOperacoes;

public class Multiplicacao implements IOperacao{
    
    @Override
    public double calcula(double valor1, double valor2) {
        return valor1 * valor2;
    }

    @Override
    public String getNomeOperacao() {
        return "Multiplicacao";
    }
    
}
