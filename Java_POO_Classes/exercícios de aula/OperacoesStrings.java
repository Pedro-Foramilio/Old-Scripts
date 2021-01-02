public class OperacoesStrings {
    private String texto = "";

    public String[] pega_palavras(){
        int tamanho_texto = texto.length();
        String palavra = "";
        String[] vetor = new String[contaPalavras()];
        char c_atual;
        int aux = -1;
        String pontuacao = ".,?!";
        for (int i=0; i < tamanho_texto; i++){
            //System.out.println("palavra = " + palavra);
            c_atual = texto.charAt(i);
            if (c_atual == ' '){
                //System.out.println("charAt = " + c_atual);
                //System.out.println("palavra = " + palavra);
                if ((texto.charAt(i-1) != ' ') && (pontuacao.indexOf(c_atual) == aux)){
                    //System.out.println("entro");
                    for (int j=0; j < vetor.length; j++){
                        //System.out.println(j + " " + vetor[j]);
                        if ((vetor[j] == null) || (vetor[j].equals(""))){
                            vetor[j] = palavra;
                            //System.out.println("Adicionou " + palavra);
                            palavra = "";
                            continue;
                        }
                    }
                    palavra = "";
                }
            }
            else{
                if (pontuacao.indexOf(c_atual) == -1){
                    palavra += c_atual;
                }
            }
            if ((i+1 == tamanho_texto) && (texto.charAt(i) != ' ')){
                //System.out.println("entrou no ultimo loop");
                for (int j=0; j < vetor.length; j++){
                    //System.out.println(j + " " + vetor[j]);
                    if ((vetor[j] == null) || (vetor[j].equals(""))|| (vetor[j].equals(" "))){
                        vetor[j] = palavra;
                        //System.out.println("Adicionou " + palavra);
                        break;
                    }
                }
            }
        }
        return vetor;
    }

    public void setTexto(String texto){ //guarda uma string na instancia
        this.texto = texto;
    }

    public String getTexto(){//retorna string armazenada na instancia
        return this.texto;
    }

    public int contaPalavras(){//retorna a quantidade de palavras na String armazenada por setTexto()
        int tamanho_texto = texto.length();
        int qtd_palavras = 0;
        int aux = -1;
        String pontuacao = ".,?!";
        char c_atual;
        for (int i=0; i < tamanho_texto; i++){
            c_atual = texto.charAt(i);
            if (c_atual == ' '){
                if ((texto.charAt(i-1) != ' ') && (pontuacao.indexOf(c_atual) == aux)){
                    qtd_palavras++;
                }
            }
            if (i+1 == tamanho_texto){
                if (texto.charAt(i) != ' ') qtd_palavras++;
            }
        }
        return qtd_palavras;
    }

    public double comprimentoMedioPalavras(){//retorna o comprimento médio das palavras na String armazenada por setTexto()
        String[] vetor = pega_palavras();
        double soma = 0;
        double n_palavras = 0;
        for (String palavra : vetor) {
            soma += palavra.length();
            n_palavras += 1;
        }
        return soma/n_palavras;
    }

    public String maiorPalavra(){//retorna uma String com a maior palavra na String armazenada por setTexto()
        String[] vetor = pega_palavras();
        String maior = "";
        for (int i=0; i < vetor.length; i++){
            if (vetor[i].length() > maior.length()){
            maior = vetor[i];
            }
        }
        return maior;
    }

    public int comprimentoMaiorPalavra(){//retorna o comprimento da maior palavra na String armazenada por setTexto()
        return maiorPalavra().length();
    }


}
