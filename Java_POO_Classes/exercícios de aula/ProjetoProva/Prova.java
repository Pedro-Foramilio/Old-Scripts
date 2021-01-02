package ProjetoProva;

public class Prova implements AutoCloseable {

    public Prova() {
        System.out.println("Construtor da Prova");
    }

    public void responderQuesao(int numero) {
        System.out.println("Respodendo questao " + numero);
        if (numero == 2) throw new RuntimeException("Problema na solucao.");
    }

    @Override
    public void close() {
        System.out.println("Encerrar Prova");
    }
    
}
