package classificacao;

public class ExcecaoExemploInvalido extends Exception {
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    private int qtdTreinamento;
    private int qtdPredizer;

    public ExcecaoExemploInvalido(int qtdTreinamento, int qtdPredizer) {
        this.qtdTreinamento = qtdTreinamento;
        this.qtdPredizer = qtdPredizer;
    }

    public int getQtdAtributosTreinamento() {
        return this.qtdTreinamento;
    }

    public int getQtdAtributosPredizer() {
        return this.qtdPredizer;
    }
}
