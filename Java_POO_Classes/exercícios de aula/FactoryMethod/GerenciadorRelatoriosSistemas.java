package FactoryMethod;

public class GerenciadorRelatoriosSistemas extends GerenciadorRelatorios {
    
    @Override
    public Relatorio criarRelatorio(String tipo) throws RelatorioInvalido {
        if (tipo.equals("erros")) {
            return new RelatorioErros();
        }
        else if (tipo.equals("acessos")) {
            return new RelatorioAcessos();
        } else {
            throw new RelatorioInvalido(tipo);
        }
    }
}
