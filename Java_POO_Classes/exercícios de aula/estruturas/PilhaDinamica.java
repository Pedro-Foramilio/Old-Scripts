package estruturas;

public class PilhaDinamica implements Pilha {
    private ListaLigada.NoLista topo = null;

    @Override
    public boolean empilhar(int numero) {
        ListaLigada.NoLista novo = new ListaLigada.NoLista(numero);
        novo.prox = topo;
        topo = novo;
        return true;
    }

    @Override
    public Integer desempilhar(){
        if (topo == null) return null;

        ListaLigada.NoLista item = topo;
        Integer ret = Integer.valueOf(item.numero);
        topo = topo.prox;
        
        item.prox = null;
        item = null;

        return ret;
    }
    
}
