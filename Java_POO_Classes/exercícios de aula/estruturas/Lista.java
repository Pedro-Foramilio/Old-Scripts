package estruturas;

public abstract class Lista {

    private int qtdItens = 0;

    public int getQtd() {
        return this.qtdItens;
    }

    protected void setQtd(int qtd) {
        this.qtdItens = qtd;
    }
    
    public abstract void adicionar(int numero);
    public abstract void remover(int numero);
    public abstract int buscar(int numero);
}
