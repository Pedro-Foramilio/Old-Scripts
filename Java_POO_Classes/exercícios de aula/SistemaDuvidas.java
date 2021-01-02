import ProjetoDuvida.*;

public class SistemaDuvidas {
    public static void main(String[] args) {
        FilaDuvidas<Duvida> fila = new FilaDuvidas<Duvida>("Paulo");

        fila.enfileira(new DuvidaFacil("Qual será a P2"));
        fila.enfileira(new DuvidaDificil("println é metodo de instancia ou de classe?"));
        fila.enfileira(new DuvidaMuitoDificil("Qual a diferença de ocultar e sobrepor?"));

        Duvida d = fila.desenfileira();
        while (d != null) {
            System.out.println(d);
            d = fila.desenfileira();
        }
    }
}
