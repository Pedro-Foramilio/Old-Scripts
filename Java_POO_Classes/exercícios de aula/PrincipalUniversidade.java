import universidade.*;
//import java.util.Scanner;

public class PrincipalUniversidade {
    public static void main(String[] args){

        Pessoa p1 = new Pessoa();
        p1.setNome("Pessoa 1");

        Pessoa prof = new Professor(); // é possível instancia como pessoa pq Professor extends Pessoa
        prof.setNome("Professor 1");

        Pessoa aluno1 = new Aluno("Computacao"); // é possível instancia como pessoa pq Aluno extends Pessoa
        aluno1.setNome("Aluno 1");

        System.out.println(p1.getNome());
        System.out.println(prof.getNome()); //A versão chamada é a da própria classe (tipo da instância)
        System.out.println(aluno1.getNome());
    }
}
