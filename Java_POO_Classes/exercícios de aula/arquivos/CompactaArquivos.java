/*
package arquivos;
import java.util.Scanner;

public class CompactaArquivos {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        int numeroArquivos = leitor.nextInt();
        PastaCompactada<Texto> pastaTextos = new PastaCompactada<Texto>();
        PastaCompactada<Imagem> pastaImagens = new PastaCompactada<Imagem>();
        for (int i=0; i < numeroArquivos; i++) {
            String aux = leitor.next();
            if (aux.equals("TextoTXT")) {
                TextoTXT doc = new TextoTXT();
                pastaTextos.adicionar(doc);
            }
            else if( aux.equals("TextoDOCX")) {
                TextoDOCX doc = new TextoDOCX();
                pastaTextos.adicionar(doc);
            }
            else if( aux.equals("Texto")){
                Texto doc = new Texto();
                pastaTextos.adicionar(doc);
            }
            else if(aux.equals("Imagem")){
                Imagem doc = new Imagem();
                pastaImagens.adicionar(doc);
            }
            else if( aux.equals("ImagemPNG")) {
                ImagemPNG doc = new ImagemPNG();
                pastaImagens.adicionar(doc);
            }
            else if( aux.equals("ImagemJPEG")) {
                ImagemJPEG doc = new ImagemJPEG();
                pastaImagens.adicionar(doc);
            }
        }

        pastaTextos.imprimir();
        pastaImagens.imprimir();
    }
}
*/