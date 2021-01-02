package plano;

public class AulaNula extends RuntimeException {
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public AulaNula() {
        super("Foi passada uma aula nula");
    }
    
}
