package ProjetoComparator;

import java.util.Comparator;
import java.lang.Comparable;

class ComparaPedido implements Comparator<Pedido> {
    @Override
    public int compare(Pedido o1, Pedido o2) {
        return (o1.getQtdItens() - o2.getQtdItens());
    }
}

public class Pedido implements Comparable<Pedido>{
    private int qtdItens;
    private String endereco;

    public Pedido(int qtdItens, String endereco) {
        this.qtdItens = qtdItens;
        this.endereco = endereco;
    }

    public int getQtdItens() {
        return this.qtdItens;
    }

    public String getEndereco() {
        return this.endereco;
    }

    @Override
    public String toString() {
        return "PEDIDO:" + this.getQtdItens();
    }

    @Override
    public int compareTo(Pedido o) {
        return this.getQtdItens() - o.getQtdItens();
    }
}