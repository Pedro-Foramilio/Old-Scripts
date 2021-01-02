package ProjetoProva;

public class Rascunho implements AutoCloseable {

    private String texto;

    public Rascunho(String texto) {
        this.texto = texto;
        System.out.println("Rascunho criado: " + this.texto);
    }

    @Override
    public void close() {
        System.out.println("Descartar rascunho: " + this.texto);
    }
    
}
