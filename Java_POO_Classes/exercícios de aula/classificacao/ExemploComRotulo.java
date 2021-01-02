package classificacao;

class ExemploComRotulo extends Exemplo {
    private int rotulo;

    ExemploComRotulo(double[] atributos, int rotulo) {
        super(atributos);
        this.rotulo = rotulo;
    }

    int getRotulo() {
        return this.rotulo;
    }
}
