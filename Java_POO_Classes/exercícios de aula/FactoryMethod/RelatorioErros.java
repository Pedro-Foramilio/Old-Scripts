package FactoryMethod;

public class RelatorioErros implements Relatorio{

    @Override
    public String getTipo() {
        return "Erros";
    }

    @Override
    public void imprimir() {
        System.out.println("--- Erros ---");
        System.out.println("-------------");
    }
}
