package espaco;
public class DiscoVoador {
    //private String cor = "-";
    //private int posicaoAtual = 0;
    private String tipo;

    public void darPartida(){
        System.out.println("Motor Ligado! " + this.tipo);
    }
/*
    public void irParaFrente(int metros){
        posicaoAtual += metros;
    }
    public void mudarCor(String cor){
        this.cor = cor;
    }
*/
    private boolean validarTipo(String tipo){
        return true; //(tipo.equals("A123")) || tipo.equals("A456");
    }
    public void setTipo(String tipo){
        if (validarTipo(tipo)){
            this.tipo = tipo;
        }
        else System.out.println("Erro: tipo inválido " + tipo);
    }
    public String getTipo(){
        return this.tipo;
    }
}
