package navegador;

public class AbaBuscador extends AbaNavegador {

    public void buscar(String expressao) {

        for (int i=0; i < Navegador.historico.length; i++) {
            if (Navegador.historico[i] == null) {
                Navegador.historico[i] = "Busca: " + expressao;
                break;
            }
        }
    }

    public String getTipo() {
        return "Buscador";
    }
}
