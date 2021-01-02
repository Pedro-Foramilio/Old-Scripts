package FactoryMethod;

public class RelatorioAcessos implements Relatorio {

    @Override
    public String getTipo() {
        return "Acessos";
    }

    @Override
    public void imprimir() {
        System.out.println("--- Acessos ---");
        System.out.println("-------------");
    }
}
