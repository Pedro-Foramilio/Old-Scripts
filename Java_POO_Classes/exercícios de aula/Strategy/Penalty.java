package Strategy;
import java.util.Random;


public class Penalty {
    private Jogador jogador;
    private int contagem = 0;

    public Penalty(Jogador jogador) {
        setStrategy(jogador);
    }

    public void setStrategy(Jogador jogador) {
        this.jogador = jogador;
    }

    private int getLadoDefesa() {
        Random rnd = new Random();
        return rnd.nextInt(3) +1; //retorna 1, 2 ou 3
    }

    public boolean cobrarPenalty() {
        System.out.println(String.format("--- Penalty %d ---", ++contagem));
        int ladoChute = this.jogador.chutar(); // <== aqui se chama o método de JOGADOR 
        int ladoDefesa = getLadoDefesa();

        System.out.println(String.format("chute=%d defesa=%d", ladoChute, ladoDefesa));

        return (ladoChute != ladoDefesa); //true = gol, false = defendeu
    }
}
