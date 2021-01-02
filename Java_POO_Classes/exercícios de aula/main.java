public class main {
    public static void main(String[] args){
    String texto = "Mais, uma, frase . para teste.";
    OperacoesStrings frase = new OperacoesStrings();
    frase.setTexto(texto);
    System.out.println("metodo getTexto: " + frase.getTexto());
    System.out.println("------------------------");
    System.out.println("Palavras da frase:");
    for (String palavra : frase.pega_palavras()) {
        System.out.print(palavra + ";");
        
    }
    System.out.println("\n------------------------");
    System.out.println("metodo contaPalavras 1: " + frase.contaPalavras());
    System.out.println("metodo comprimentoMaiorPalavra 2: " + frase.comprimentoMaiorPalavra());
    System.out.println("metodo comprimentoMedioPalavras 3:" + frase.comprimentoMedioPalavras());
    System.out.println("metodo maiorPalavra 4: " + frase.maiorPalavra());
    }
}
