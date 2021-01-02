package estruturas;

public class PilhaEstatica implements Pilha{

    private int[] itens;
    private int topo = -1;

    public PilhaEstatica(int tamanho) {
        this.itens = new int[tamanho];
    }

    @Override
    public boolean empilhar(int numero) {
        if (topo == itens.length -1) return false;

        itens[++topo] = numero; //++topo => incrementa o valor topo e então usa
        return true;
    }

    @Override
    public Integer desempilhar() {
        if (topo == -1) return null;

        return Integer.valueOf(itens[topo--]); //topo-- => usa o valor de topo e entao desincrementa o valor
    }

}
