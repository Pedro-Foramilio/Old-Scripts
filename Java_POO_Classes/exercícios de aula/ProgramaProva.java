import autocorrecao.Alternativa;
import autocorrecao.Pergunta;
import autocorrecao.Prova;

public class ProgramaProva {
    public static void main(String[] args) {
        try{
            Prova p1 = new Prova(2);

            Pergunta q1 = new Pergunta(3, "qual o valor de 10 x 10?");
            //adicionando com método original
            q1.adicionarAlternativa(true, new Alternativa("100"));
            q1.adicionarAlternativa(false, new Alternativa("1"));
            q1.adicionarAlternativa(false, new Alternativa("10"));

            Pergunta q2 = new Pergunta(2, "Qual o valor de 50 x 50?");
            //adicionando com método de sobrecarga
            q2.adicionarAlternativa(false, "5");
            q2.adicionarAlternativa(true, "2500");


            p1.adicionarPergunta(q1);
            p1.adicionarPergunta(q2);

            Prova p2 = p1.clone();
            //p2.apagarPerguntas();
            q2.setTextoPergunta("Qual o valor de 2 + 3?");

            p1.imprimir();
            p2.imprimir();
        } catch (Exception e){
            System.out.println("Ocorreu um erro: " + e.toString());
        }
    }
}
