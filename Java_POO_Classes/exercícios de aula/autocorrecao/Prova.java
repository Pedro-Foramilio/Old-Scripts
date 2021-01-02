package autocorrecao;

public class Prova implements Cloneable {
    private Pergunta[] perguntas;
    private int indiceUltimaPergunta;
    private String titulo;

    public Prova(int qtdPerguntas){
        this.perguntas = new Pergunta[qtdPerguntas];
        this.indiceUltimaPergunta = -1;
        this.titulo = "PROVA";
    }

    //#region Cópia Rasa
    /*
    @Override
    public Prova clone() throws CloneNotSupportedException {
        return (Prova) super.clone();
    }
    */
    //#endregion

    //#region Cópia Profunda

    @Override
    public Prova clone() throws CloneNotSupportedException {
        Prova novaProva = (Prova) super.clone();
        novaProva.perguntas = this.perguntas.clone();
        for (int i=0; i <= this.indiceUltimaPergunta; i++) {
            novaProva.perguntas[i] = this.perguntas[i].clone();
        }
        return novaProva;
    }

    //#endregion

    public void adicionarPergunta(Pergunta novaPergunta){
        if (indiceUltimaPergunta+1 >= perguntas.length){
            System.out.println("Vetor de perguntas cheio");
        }else{
            perguntas[++indiceUltimaPergunta] = novaPergunta;
        }
    }
    
    public void imprimir(){
        System.out.println("------------------"+this.titulo+"-------------------");
        for (Pergunta elemento : this.perguntas){
            if (elemento != null) elemento.imprimir();
        }
    }

    public void apagarPerguntas() {
        for (int i=0; i <= this.indiceUltimaPergunta; i++) {
            this.perguntas[i] = null;
        }
        this.indiceUltimaPergunta = -1;
    }
}
