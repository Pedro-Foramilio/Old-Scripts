import universidade2.*;

public class ProgramaUniversidade2 {

    public static void main(String[] args){
        Pessoa p1 = new Pessoa();
        p1.setNomeSobrenome("NomePessoa", "SobrenomePessoa");
        Aluno p2 = new Aluno();
        p2.setNomeSobrenome("NomeAluno", "SobrenomeAluno");
        Professor p3 = new Professor();
        p3.setNomeSobrenome("NomeProfessor", "SobrenomeProfessor");

        System.out.println(p1.getEmail());
        System.out.println(p1.getVinculo());
        System.out.println(p2.getEmail());
        System.out.println(p2.getVinculo());
        System.out.println(p3.getEmail());
        System.out.println(p3.getVinculo());

    }
}
