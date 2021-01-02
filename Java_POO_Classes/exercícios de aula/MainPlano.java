import plano.*;

public class MainPlano {
    
    public static void main(String[] args) {

        try {

            PlanoDeAulas plano = new PlanoDeAulas(7);

            Aula a1 = new Teorica("Introducao");
            Aula a2 = new Teorica("Orientacao a Objetos");
            Aula a3 = new Pratica("Revisao");
            Aula p1 = new Prova(2, "Prova 1");
            //Aula r1 = new AulaRevisao();
            
            plano.adicionarAula(a1);
            plano.adicionarAula(a2);
            plano.adicionarAula(p1);
            plano.adicionarAula(a3);
            plano.adicionarAula(a1);
            plano.adicionarAula(a1);
            plano.adicionarAula(a1);
            
            
            
            
            PlanoDeAulas plano2 = new PlanoDeAulas(plano); //copia por construtor de copia
            Aula p2 = new Prova(3, "Prova 2");
            plano2.adicionarAula(p2);
            
            plano.imprimir();
            plano.imprimirFormulaAvaliacao();
            plano2.imprimir();
            plano2.imprimirFormulaAvaliacao();

            
        } catch (RevisaoNaoPermitida e) {
            System.out.println("Revisao nao eh permitida: " + e.toString());
        } catch (TemMuitaAula e) {
            System.out.println("Passou do limite de aulas: " + e.toString());
            System.out.println("Limite de aulas: " + e.getLimite());
            System.out.println("Aula: " + e.getAula().getDescricao());
        } catch (Exception e) {
            System.out.println("Erro: " + e.toString());
        }
    }
}
