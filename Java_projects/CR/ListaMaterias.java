package CR;

import java.util.ArrayList;

public class ListaMaterias {
    private ArrayList<Materia> lista;

    public ListaMaterias() {
        this.lista = new ArrayList<Materia>();
    }

    public void addMateria(Materia m) {
        lista.add(m);
    }

    public void addMateria(Materia m, int i) {
        lista.add(i, m);
    }

    public Materia getItem(int i) {
        return lista.get(i);
    }

    public void removerItem(int i) {
        //remove com base no index
        lista.remove(i);
    }

    public void removerItem(Materia m) {
        lista.remove(m);
    }

    public int getQtdItens() {
        return lista.size();
    }

}
