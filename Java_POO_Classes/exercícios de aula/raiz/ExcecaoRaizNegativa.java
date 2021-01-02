package raiz;

public class ExcecaoRaizNegativa extends Exception {
    /**
     *
     */
    private static final long serialVersionUID = 1L;
    private double parteComplexa;

    public ExcecaoRaizNegativa(double parteComplexa) {
        this.parteComplexa = parteComplexa;
    }

    public String dominioComplexos() {
        double raiz = Math.sqrt(parteComplexa);
        return "0 + " + raiz + "i";
    }

    @Override
    public String toString() {
        return "Raiz quadrada de numero negativo nao existe no dominio dos reais";
    }
    
}
