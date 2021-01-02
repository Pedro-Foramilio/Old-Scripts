package ProjetoDuvida;

import java.util.ArrayList;

public class Fila< T > {

    private ArrayList< T > fila = new ArrayList< T >();

    public void enfileira(T item) {
        fila.add(item);
    }

    public T desenfileira() {
        if (fila.size() == 0) return null;

        T item = fila.get(0);
        fila.remove(0);
        return item;
    }
    
}
