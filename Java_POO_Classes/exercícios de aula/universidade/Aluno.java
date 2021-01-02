package universidade;

public class Aluno extends Pessoa {
    private String curso;
    private int creditosCursados = 0;
    public Aluno(String curso){
        this.curso = curso;
    }
    public void adicionaCreditos(int creditos){
        this.creditosCursados += creditos;
    }
    public void imprimirSituacaoAluno(){
        System.out.println("Curso: " + this.curso + " Creditos: " + this.creditosCursados);
    }
}
