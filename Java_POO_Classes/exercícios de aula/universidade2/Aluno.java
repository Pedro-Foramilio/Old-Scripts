package universidade2;

public class Aluno extends Pessoa
{

    @Override
    public String getEmail()
    {
        return this.nome + "." + this.sobrenome + "@aluno.ufabc.edu.br";
    }

    @Override
    public String getVinculo()
    {
        return "Aluno da UFABC";
    }
}
