package plano;

public class RevisaoNaoPermitida extends Exception {

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public RevisaoNaoPermitida() {
        super("Nao pode ter aula de revisao");
    }
    
}
