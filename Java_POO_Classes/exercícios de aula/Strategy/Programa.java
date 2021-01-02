package Strategy;
import java.util.Scanner;

public class Programa {
    public static void main(String[] args) {

        Scanner leitor = new Scanner(System.in);
        System.out.println("Qual estratégia? (1-A, 2-B)");
        int estrategia = leitor.nextInt();

        Jogador j = null;
        if (estrategia == 1) {
            j = new JogadorEstrategiaA();
            System.out.println("Estrategia A");
        }
        else if (estrategia == 2) {
            j = new JogadorEstrategiaB();
            System.out.println("Estrategia B");
        }
        else {
            System.out.println("Estrategia invalida");
            leitor.close();
            return;
        }
        System.out.println();
        Penalty p = new Penalty(j);
        int gols = 0, defesas = 0;

        for (int i=0; i < 5; i++) {
            if (p.cobrarPenalty()) {
                gols++;
            } else {
                defesas++;
            }
        }

        System.out.println("--- Resultado ---");
        System.out.println(String.format("Gols = %d Defesas = %d", gols, defesas));
        leitor.close();
    }
}
