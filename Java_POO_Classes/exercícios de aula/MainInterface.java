import ProjetoOperacoes.*;

public class MainInterface {
    public static void main(String[] args) {

        IOperacao op1 = new Soma();

        double r1 = op1.calcula(10, 20);
        System.out.println(op1.getNomeOperacao() + " " + r1);

        IOperacao op2 = new Multiplicacao();

        double r2 = op2.calcula(10, 20);
        System.out.println(op2.getNomeOperacao() + " " + r2);
    }
}
