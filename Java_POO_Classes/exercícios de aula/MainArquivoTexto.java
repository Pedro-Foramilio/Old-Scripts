
public class MainArquivoTexto {

    public static void main(String[] agrs) {
        try {
            
            ArquivoTexto texto = new ArquivoTexto(5);
            texto.modificarLinha(0, "Linha 1");
            texto.modificarLinha(1, "Linha 2");
            texto.modificarLinha(2, "Linha 3");
            texto.modificarLinha(3, "Linha 4");
            texto.modificarLinha(4, "Linha 5");
            System.out.println("----------------");
            System.out.println("Texto Original:");
            System.out.print(texto.ler() + "\n");
            System.out.println("----------------");
            ArquivoTexto backup = texto.criarBackup();
            System.out.println("Criado um backup");
            System.out.println("----------------");
            System.out.println("Mudando linha 3 para 'Linha 3 alterada'");
            backup.modificarLinha(2, "Linhas 3 alterada");
            System.out.println("----------------");
            System.out.println("Texto Original:");
            System.out.print(texto.ler() + "\n");
            System.out.println("----------------");
            System.out.println("Texto Backup Alterado:");
            System.out.print(backup.ler() + "\n");
            ArquivoTexto atalhoOriginal = texto.criarAtalho();
            System.out.println("Criado um atalho para o texto original");
            atalhoOriginal.modificarLinha(0, "Linha 1 alterada");
            System.out.println("----------------");
            System.out.println("Texto original:");
            System.out.println(texto.ler());
            System.out.println("----------------");
            System.out.println("Atalho:");
            System.out.print(atalhoOriginal.ler());
            System.out.println("----------------");
            System.out.println("Backup:");
            System.out.print(backup.ler());


    } catch (Exception e) {
            System.out.println("Erro: " + e.toString());
        }
    }
}
