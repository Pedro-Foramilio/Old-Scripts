package FactoryMethod;
import java.util.ArrayList;

public abstract class GerenciadorRelatorios {
    
    private ArrayList<Relatorio> relatorios = new ArrayList<Relatorio>();

    public abstract Relatorio criarRelatorio(String tipo) throws RelatorioInvalido;

    public void gerarRelatorio(String tipo) throws RelatorioInvalido{
        Relatorio r = criarRelatorio(tipo);
        r.imprimir();
        relatorios.add(r);
    }

    public void imprimirListaRelatorios() {
        System.out.println("Lista relatorios:");

        int i = 0;
        for (Relatorio r : relatorios) {
            i++;
            System.out.println(String.format("%d. %s", i, r.getTipo()));
        }
    }
}
