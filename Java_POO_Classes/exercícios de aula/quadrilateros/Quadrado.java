package quadrilateros;

public class Quadrado extends Retangulo{
    public void setLados(double lado1) {
        super.setLados(lado1, lado1);
    }
    
    @Override
    public String getPropriedades() {
        return super.getPropriedades() + " Todos os lados tem mesmo tamanho.";
    }

}
