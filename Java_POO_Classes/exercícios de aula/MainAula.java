import aula.*;

public class MainAula {
    public static void main(String[] args) {
        Aula aulaTeorica = new Teorica("Polimorfismo");
        System.out.println("Aula: " + aulaTeorica.getDescricao());
        System.out.println("Tipo Aula: " + aulaTeorica.getTipo());
    }   
}
