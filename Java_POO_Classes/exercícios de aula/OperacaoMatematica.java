public class OperacaoMatematica {
    private int valor1;
    private int valor2;
    private int resultado;
    
    public void setValor1(int valor){
        this.valor1=valor;
    }
    public void setValor2(int valor){
        this.valor2=valor;
    }
    public int getResultado(){
        return this.resultado;
    }
    
    public void executaOperacao(int operacao){
        switch(operacao){
            case 1:
                resultado = valor1+valor2;
                break;
            case 2:
                resultado = valor1-valor2;
                break;
            case 3:
                resultado = valor1*valor2;
                break;
            case 4:
                resultado = valor1/valor2;
                break;
        }
    }
}
