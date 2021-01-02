package navegador;

public class AbaRedeSocial extends AbaNavegador{

    public void postar(String texto) {

        for (int i=0; i < Navegador.historico.length; i++) {
            if (Navegador.historico[i] == null) {
                Navegador.historico[i] = "Post: " + texto;
                break;
            }
        }
    }

    public String getTipo() {
        return "RedeSocial";
    }
}
