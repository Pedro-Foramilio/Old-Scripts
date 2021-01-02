package projeto_aluno;

public class Aluno {
    private String nome;
    private int ra;
    private static int qtdAlunos = 0;

    public Aluno(int ra, String nome){
        qtdAlunos++;
        this.ra = ra;
        this.nome = nome;
    }

    public String getNome(){
        return this.nome;
    }
    public int getRA(){
        return this.ra;
    }

    public static int getQtdAlunos(){
        return qtdAlunos; //não utiliza o this, pq static não acessa instancia
    }
    
}
