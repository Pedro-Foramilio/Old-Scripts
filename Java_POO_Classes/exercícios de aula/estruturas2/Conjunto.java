package estruturas2;

public class Conjunto implements Lista{
    private int qtdItens = 0;
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
    public int getQtd() {
        return qtdItens;
    }

    @Override
    public void adicionar(int numero) {
        NoLista novo = new NoLista(numero);

        if (this.inicio == null) {
            this.inicio = novo;
        }

        else {
            //verifica se o numero já existte
            for (NoLista atual = this.inicio; atual != null; atual = atual.prox) {
                if (atual.numero == numero) return;
            }

            NoLista anterior = null;
            NoLista atual = inicio;
            while (atual != null) {
                anterior = atual;
                atual = atual.prox;
            }
            anterior.prox = novo;
        }
        qtdItens++;
    }
    
    @Override
    public void remover(int numero) {
        if (this.inicio == null) return;

        NoLista anterior = null;
        NoLista atual = inicio;
        while(atual != null && atual.numero != numero) {
            anterior = atual;
            atual = atual.prox;
        }
        if (atual == null) return;

        if (anterior == null) {
            this.inicio = atual.prox;
        }
        else {
            anterior.prox = atual.prox;
        }
        atual.prox = null;
        atual = null;
        qtdItens--;
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
            if (atual.prox == null) {
                listaStr += atual.numero;
            }
            else {
                listaStr += atual.numero + " ";
            }
        }
        return listaStr;
    }

    public static Conjunto uniao(Conjunto a, Conjunto b) {
        Conjunto uniao = new Conjunto();
        for (NoLista aAtual = a.inicio; aAtual != null; aAtual = aAtual.prox) {
            uniao.adicionar(aAtual.numero);
        }
        for (NoLista bAtual = b.inicio; bAtual != null; bAtual = bAtual.prox) { //percorre todos elementos de b
            boolean aux = true;
            for (NoLista atual = a.inicio; atual != null; atual = atual.prox) { //percorre todos de a
                if (bAtual == atual) {
                    aux = false;
                    break;
                }
            }
            if (aux) {
                uniao.adicionar(bAtual.numero);
            }
        }
        return uniao;
    }

    public static Conjunto intersecao(Conjunto a, Conjunto b) {
        Conjunto intersecao = new Conjunto();
        for (NoLista aAtual = a.inicio; aAtual != null; aAtual = aAtual.prox) {
            for (NoLista bAtual = b.inicio; bAtual != null; bAtual = bAtual.prox) {
                //bate todos elementos de B com o elemento de A dessa vez
                if (aAtual.numero == bAtual.numero) {
                    intersecao.adicionar(aAtual.numero);
                }
            }
        }
        return intersecao;
    }
}
