import ProjetoProva.Prova;
import ProjetoProva.Rascunho;

public class MainProjetoProva {
    public static void main(String[] args) {

        try(
            Prova p1 = new Prova();
            Rascunho r1 = new Rascunho("Classe abstrata não pode ser instanciada");
            Rascunho r2 = new Rascunho("Usar o Override na sobreposicao de metodos");
        ) {
            p1.responderQuesao(1);
            p1.responderQuesao(2);
            p1.responderQuesao(3);
        }
        

    }
}
/* outro metodo: try with finally

public class MainProjetoProva {
    public static void main(String[] args) {
                
        Prova p1 = new Prova();
        try {
            p1.responderQuesao(1);
            p1.responderQuesao(2);
            p1.responderQuesao(3);
        } finally {
            p1.close();
        }

    }

}

*/