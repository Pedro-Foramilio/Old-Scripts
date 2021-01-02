package estruturas;

public class ListaLigada extends Lista {
    
    private NoLista inicio = null;

    static class NoLista {
        //implementada como static pois nao precisa acessar nada na classe que a contem
        int numero;
        NoLista prox = null;

        NoLista(int numero) {
            this.numero = numero;
        }
    }

    @Override
    public void adicionar(int numero) { //adicionar no final
        NoLista novo = new NoLista(numero);

        if (this.inicio == null) {
            this.inicio = novo;
        } else {
            NoLista anterior = null;
            NoLista atual = inicio;
            while (atual != null) {
                //Caminha até o atual ser nulo, então o anterior tem o ultimo elemento
                anterior = atual;
                atual = atual.prox;
            }
            anterior.prox = novo; //anterior (ultimo) aponta para o novo
        }
        super.setQtd(super.getQtd() + 1);
    }

    @Override
    public void remover(int numero) {
        if (this.inicio == null) return;

        NoLista anterior = null;
        NoLista atual = inicio;
        while (atual != null && atual.numero != numero) {
            anterior = atual;
            atual = atual.prox;
        }
        if (atual == null) return; //numero nao encontrado na lista

        //se chegou ate aqui, achou o elemento a ser removido
        if (anterior == null) { //elemento a remover é o primeiro elemento
            this.inicio = atual.prox;
        }
        else {
            anterior.prox = atual.prox;
        }
        atual.prox = null; //item atual a ser removido setado pra nulo
        atual = null; //idem acima

        super.setQtd(super.getQtd() - 1);
    }

    @Override
    public int buscar(int numero) {
        int i = 0;
        for (NoLista atual = this.inicio; atual != null; atual = atual.prox) {
            if (atual.numero == numero) return i;
            i++;
        }
        return -1;
    }

    @Override
    public String toString() {
        String listaStr = "";
        for (NoLista atual = this.inicio; atual != null; atual = atual.prox) {
            listaStr += atual.numero + " ";
        }
        return listaStr;
    }
    
}
