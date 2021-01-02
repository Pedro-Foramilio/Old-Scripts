package classificacao;

class Exemplo {
    private double[] atributos;

    Exemplo(double[] atributos) {
        this.atributos = atributos.clone();
    }
    
    double[] getAtributos() {
        return this.atributos;
    }
}
