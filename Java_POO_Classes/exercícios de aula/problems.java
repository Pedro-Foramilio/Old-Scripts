import java.util.Scanner;
public class problems {

    public static void main(String[] args) {

        Scanner read = new Scanner(System.in);
        int len;
        System.out.println("How many numbers?");
        len = read.nextInt();
        int[] vector = new int[len];

        //ler vetor
        for (int i=0; i < vector.length; i++){
            vector[i] = read.nextInt();
        }
        //contar impares - foreach
        int count = 0;
        for (int number: vector){
            if (number % 2 != 0){count++;}
        }
        System.out.println("There are " + count + " odd numbers");

    }

}
