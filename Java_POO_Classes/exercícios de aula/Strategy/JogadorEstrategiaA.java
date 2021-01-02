package Strategy;
import java.util.Random;

public class JogadorEstrategiaA implements Jogador{

    @Override
    public int chutar() {
        Random rnd = new Random();
        return rnd.nextInt(3) +1; //retorna 1, 2 ou 3
    }
    
}
