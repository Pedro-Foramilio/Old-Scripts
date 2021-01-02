package geometria;

public class Comparacao {

    public static <T extends Comparable<T>> T maiorElemento(T[] v) {
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
        return v[v.length-1];
    }

    public static <T extends Comparable<T>> T menorElemento(T[] v) {
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
        return v[0];
    }
    
}
