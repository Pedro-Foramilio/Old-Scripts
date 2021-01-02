package FactoryMethod;

public class Programa {
    public static void main(String[] args) {
        GerenciadorRelatorios geradorRelatorios1 = new GerenciadorRelatoriosSistemas();
        try {
            geradorRelatorios1.gerarRelatorio("erros");
            geradorRelatorios1.gerarRelatorio("acessos");
            geradorRelatorios1.imprimirListaRelatorios();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    
}
