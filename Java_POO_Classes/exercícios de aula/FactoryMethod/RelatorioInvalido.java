package FactoryMethod;

public class RelatorioInvalido extends Exception {

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public RelatorioInvalido(String tipo) {
        super("Relatorio invalido: tipo = " + tipo);
    }
    
}
