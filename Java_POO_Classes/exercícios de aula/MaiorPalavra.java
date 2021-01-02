import java.util.Scanner;

public class MaiorPalavra {
    public static int comprimento_maior_palavra(String texto) {
        int tamanho_texto = texto.length();
        int tamanho_segmento = 0;
        int maior_palavra = 0;
        char c_atual;
        for (int i=0; i < tamanho_texto; i++){
            c_atual = texto.charAt(i);
            System.out.println("c_atual = " + c_atual);
            if (c_atual != ' '){
                System.out.println("entrou no seg++, seg = " + tamanho_segmento);
                tamanho_segmento++;
            }
            if ((c_atual == ' ') || (i+1 == tamanho_texto)){
                System.out.println("entrou no else");
                System.out.println("maior palavra = " + maior_palavra);
                if (tamanho_segmento >= maior_palavra){
                    System.out.println("entrou no if t > m");
                    maior_palavra = tamanho_segmento;
                }
                tamanho_segmento = 0;
            }
        }
        return maior_palavra;
    	
    }
    
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
		
        String texto = leitor.nextLine();
        
        System.out.println(comprimento_maior_palavra(texto));
    }
}