package plano;

public class TemMuitaAula extends Exception{
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    private int limite;
    private Aula aula;
    public TemMuitaAula(int limite, Aula aula) {
        super("Tem Muita Aula");
        this.limite = limite;
        this.aula = aula;
    }

    public int getLimite() {
        return this.limite;
    }

    public Aula getAula() {
        return this.aula;
    }
}
