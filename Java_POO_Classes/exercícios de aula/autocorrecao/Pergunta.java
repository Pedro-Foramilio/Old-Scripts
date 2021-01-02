package autocorrecao;

public class Pergunta implements Cloneable {
    private String textoPergunta;
    private Alternativa[] alternativas;
    private int indiceAlternativaCorreta;
    private int indiceUltimaAlternativa;

    public Pergunta(int qtdAlternativas, String textoPergunta){
        this.alternativas = new Alternativa[qtdAlternativas];
        this.setTextoPergunta(textoPergunta);
        this.indiceUltimaAlternativa = -1;
        this.indiceAlternativaCorreta = -1;
    }

    public void setTextoPergunta(String textoPergunta){
        this.textoPergunta = textoPergunta;
    }

    public String getTextoPergunta(){
        return this.textoPergunta;
    }

    //MÉTODO ORIGINAL
    public void adicionarAlternativa(boolean correta, Alternativa alternativa) throws Exception{
        if (indiceUltimaAlternativa + 1 >= alternativas.length){
            //System.out.println("Lista alternativas cheia");
            throw new Exception("Lista de Alternativas esta cheia");
        }
        else{
            if (correta){
                if (indiceAlternativaCorreta == -1){
                    indiceAlternativaCorreta = indiceUltimaAlternativa + 1;
                }
                else{
                    //System.out.println("Existe outra alternativa correta");
                    throw new Exception("Existe outra alternativa correta");
                    //return;
                }
            }
            alternativas[++indiceUltimaAlternativa] = alternativa;
        }
    }

    //SOBRECARGA DE MÉTODO
    public void adicionarAlternativa(boolean correta, String alternativa) throws Exception{
        //não é obrigado redirecionar ao original
        this.adicionarAlternativa(correta, new Alternativa(alternativa));
    }

    public void imprimir(){
        System.out.println("-------------------------------------");
        System.out.println("Enunciado: " + this.getTextoPergunta());
        for (Alternativa elemento : alternativas){
            System.out.println("- " + elemento.getDescricao());
        }
    }

    @Override //deep copy
    public Pergunta clone() throws CloneNotSupportedException {
        Pergunta novaPergunta = (Pergunta) super.clone();
        novaPergunta.alternativas = this.alternativas.clone();
        for (int i=0; i <= this.indiceUltimaAlternativa; i++) {
            if (this.alternativas[i] != null) {
                novaPergunta.alternativas[i] = this.alternativas[i].clone();
            }
        }
        return novaPergunta;
    }
}
