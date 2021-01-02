package AulaModClass;


public class Programa {
    public static void main(String[] args) {

        ClasseTeste instancia = new ClasseTeste();
        ClasseTeste.ClasseTestePublic c4 = instancia.new ClasseTestePublic();
        c4.getClass();
    }
}
