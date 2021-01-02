package ProjetoComparator;

import java.util.Random;
import java.util.Comparator;


class ComparaNumeroCrescente implements Comparator<Integer> {
    @Override
    public int compare(Integer o1, Integer o2) {
        return (o1 - o2);
    }
}

class ComparaNumeroDecrescente implements Comparator<Integer> {
    @Override
    public int compare(Integer o1, Integer o2) {
        return -1 * (o1 - o2);
    }
}

public class ProgramaPrincipal {

    public static void imprimir(Object[] v) {
        for (int i=0; i < v.length; i++) {
            System.out.print(v[i] + " ");
        }
        System.out.println();
    }

    public static <T> void selectionSort(T[] v, Comparator<T> cmp) {
        for (int i=0; i < v.length-1; i++) {
            int indice_menor = i;
            for (int k=i+1; k < v.length; k++) {
                if ( cmp.compare(v[k], v[indice_menor]) < 0 ) {
                    indice_menor = k;
                }
            }
            if (i != indice_menor) {
                T tmp = v[i];
                v[i] = v[indice_menor];
                v[indice_menor] = tmp;
            }
        }
    }

    public static <T extends Comparable<T>> void ordenar(T[] v) {
        for (int i=0; i < v.length-1; i++) {
            int indice_menor = i;
            for (int k=i+1; k < v.length; k++) {
                if ( v[k].compareTo(v[indice_menor]) < 0 ) {
                    indice_menor = k;
                }
            }
            if (i != indice_menor) {
                T tmp = v[i];
                v[i] = v[indice_menor];
                v[indice_menor] = tmp;
            }
        }
    }


    public static void main(String[] args) {
        Random rnd = new Random();
        Integer[] v = new Integer[10];
        for (int i=0; i < v.length; i++) {
            v[i] = rnd.nextInt(50);
        }
        imprimir(v);
        ProgramaPrincipal.<Integer>selectionSort(v, new ComparaNumeroCrescente());
        imprimir(v);
        ProgramaPrincipal.<Integer>selectionSort(v, new ComparaNumeroDecrescente());
        imprimir(v);
        System.out.println("--------------------------");
        
        Pedido[] vetorPedidos = new Pedido[10];
        for (int i=0; i < vetorPedidos.length; i++) {
            vetorPedidos[i] = new Pedido(rnd.nextInt(50), "Endereco");
        }
        
        imprimir(vetorPedidos);
        ProgramaPrincipal.<Pedido>selectionSort(vetorPedidos, new ComparaPedido());
        imprimir(vetorPedidos);
        System.out.println("--------------------------");

        Integer[] v1 = new Integer[10];
        for (int i=0; i < v1.length; i++) {
            v1[i] = rnd.nextInt(50);
        }
        imprimir(v1);
        ProgramaPrincipal.<Integer>ordenar(v1);
        imprimir(v1);
        System.out.println("--------------------------");
        Pedido[] vetorPedidos1 = new Pedido[10];
        for (int i=0; i < vetorPedidos1.length; i++) {
            vetorPedidos1[i] = new Pedido(rnd.nextInt(50), "Endereco");
        }
        
        imprimir(vetorPedidos1);
        ProgramaPrincipal.<Pedido>ordenar(vetorPedidos1);
        imprimir(vetorPedidos1);
        System.out.println("--------------------------");
    }
}
