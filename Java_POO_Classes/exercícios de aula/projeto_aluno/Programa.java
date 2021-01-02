package projeto_aluno;

public class Programa {
    public static void main(String[] args){
        Aluno a1 = new Aluno(123, "ABC");
        Aluno a2 = new Aluno(456, "DEF");

        System.out.println(a1.getNome());
        System.out.println(a2.getNome());
        System.out.println(Aluno.getQtdAlunos());
    }
}
