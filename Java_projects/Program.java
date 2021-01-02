import CR.*;
import java.util.Scanner;

public class Program {

//#region Metodos apoio
    private static double calculaCR(ListaMaterias materias) throws Exception{
        double nota = 0;
        double creditos = 0;
        
        for (int i=0; i < materias.getQtdItens(); i++) {
            Materia materiaAtual = materias.getItem(i);
            nota += materiaAtual.notaMateria();
            creditos += materiaAtual.getCreditos();
        }

        double CR = nota / creditos;
        return CR;

    }

    private static double calculaCR(ListaMaterias materias, double crAtual, double creditosCursados) throws Exception {
        double notaAnterior = crAtual * creditosCursados;
        double creditos = creditosCursados;

        for (int i=0; i < materias.getQtdItens(); i++) {
            Materia materiaAtual = materias.getItem(i);
            notaAnterior += materiaAtual.notaMateria();
            creditos += materiaAtual.getCreditos();
        }

        double CR = notaAnterior / creditos;
        return CR;
    }

    private static void imprimirListaMaterias(ListaMaterias lista) {
        System.out.println("Confira as materias: ");
        for (int i=0; i < lista.getQtdItens(); i++) {
            System.out.println("Materia " + (i+1) + ":");
            System.out.println(lista.getItem(i));
        }
        System.out.println();
    }

    private static void validaSimNao(String msg) throws Exception {
        String r = msg.toUpperCase();
        if 
            (r.equals("S") || r.equals("N")) return;
        else 
            throw new Exception("Respota precisa ser S/N");
    }

//#endregion

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        try {
            ListaMaterias lista = new ListaMaterias();
            String pergunta = "";
            double crAnterior = 0;
            double creditosCursados = 0;

            boolean crAntigo = false;
            System.out.println("Possui CR atual?(s/n)");
            pergunta = leitor.next().toUpperCase();
            validaSimNao(pergunta);
            if (pergunta.equals("S")) crAntigo = true;
            
            if (crAntigo) {
                System.out.println("Insira CR antigo: ");
                crAnterior = leitor.nextDouble();
                System.out.println("Quantos creditos ja foram cursados?: ");
                creditosCursados = leitor.nextDouble();
                
                System.out.println("Quantas materias serao concluidas?: ");
                int n = leitor.nextInt();
                System.out.println("Insira o coneito e quantos creditos possui cada materia:");

                for (int i=1; i <= n; i++) {
                    System.out.println("Materia " + i + ":");
                    System.out.println("Conceito: ");
                    String conceitoAux = leitor.next();
                    System.out.println("Creditos da materia: ");
                    int creditoAux = leitor.nextInt();
                    System.out.println("------------");
                    lista.addMateria(new Materia(conceitoAux, creditoAux));
                }

                
                imprimirListaMaterias(lista);
                System.out.println("Materias Corretas?(s/n)");
                String validador = leitor.next().toUpperCase();
                validaSimNao(validador);

                if (validador.equals("N")) {
                    boolean ok = false;
                    while (! ok) {
                        System.out.println("Qual materia esta errada? (partindo de 1)");
                        int pos = leitor.nextInt();
                        System.out.println("Qual a quantidade de creditos Correta?");
                        int creditoOK = leitor.nextInt();
                        System.out.println("Qual o conceito Correto?");
                        String conceitoOK = leitor.next();
                        lista.removerItem(pos-1);
                        lista.addMateria(new Materia(conceitoOK, creditoOK), (pos-1));

                        imprimirListaMaterias(lista);
                    System.out.println("Materias Corretas?(s/n)");
                    validador = leitor.next().toUpperCase();
                    validaSimNao(validador);
                    if (validador.equals("S")) ok = true;
                    }
                }

                double CR = calculaCR(lista, crAnterior, creditosCursados);
                System.out.println("----------------");
                System.out.println("CR = " + CR);
            } else {

                System.out.println("Quantas materias serao concluidas?: ");
                int n = leitor.nextInt();
                System.out.println("Insira o coneito e quantos creditos possui cada materia:");

                for (int i=1; i <= n; i++) {
                    System.out.println("Materia " + i + ":");
                    System.out.println("Conceito: ");
                    String conceitoAux = leitor.next();
                    System.out.println("Creditos da materia: ");
                    int creditoAux = leitor.nextInt();
                    System.out.println("------------");
                    lista.addMateria(new Materia(conceitoAux, creditoAux));
                }

                
                imprimirListaMaterias(lista);
                System.out.println("Materias Corretas?(s/n)");
                String validador = leitor.next().toUpperCase();
                validaSimNao(validador);

                if (validador.equals("N")) {
                    boolean ok = false;
                    while (! ok) {
                        System.out.println("Qual materia esta errada? (partindo de 1)");
                        int pos = leitor.nextInt();
                        System.out.println("Qual a quantidade de creditos Correta?");
                        int creditoOK = leitor.nextInt();
                        System.out.println("Qual o conceito Correto?");
                        String conceitoOK = leitor.next();
                        lista.removerItem(pos-1);
                        lista.addMateria(new Materia(conceitoOK, creditoOK), (pos-1));

                        imprimirListaMaterias(lista);
                    System.out.println("Materias Corretas?(s/n)");
                    validador = leitor.next().toUpperCase();
                    validaSimNao(validador);
                    if (validador.equals("S")) ok = true;
                    }
                }

                double CR = calculaCR(lista);
                System.out.println("----------------");
                System.out.println("CR = " + CR);

            }
        } catch (Exception e) {
            System.out.println(e.toString());
        } finally {
            leitor.close();
            System.out.println("-----------------");
            System.out.println("Scanner closed");
            System.out.println("Thread end");
            System.out.println("-----------------");
        }
    }
}
