package universidade2;

public class Professor extends Pessoa
{
    
    @Override
    public String getEmail()
    {
        return this.nome + "." + this.sobrenome + "@ufabc.edu.br";
    }

    @Override
    public String getVinculo()
    {
        return "Professor da UFABC";
    }

}
