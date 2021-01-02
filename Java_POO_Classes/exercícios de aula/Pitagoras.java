import java.util.Scanner;
public class Pitagoras {
    
    public static void main(String[] args){
        Scanner leitor = new Scanner(System.in);
        double c = leitor.nextFloat();
        double b = leitor.nextFloat();
        double a = leitor.nextFloat();
        double resultado = 0;
        //c² = a² + b²
        if (c == 0.0){
            resultado = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));
        }
        //b² = c² - a²
        else if (b == 0.0){
            resultado = Math.sqrt(Math.pow(c, 2) - Math.pow(a, 2));
        }
        // a² = c² - b²
        else if (a == 0.0){
            resultado = Math.sqrt(Math.pow(c, 2) - Math.pow(b, 2));
            
        }
        System.out.println(resultado);
    }
    
}
