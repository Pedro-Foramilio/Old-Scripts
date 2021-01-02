import estruturas.*;

public class MainEstrutura {
    public static void main(String[] args) {

        System.out.println("Teste Lista Ligada");
        Lista l1 = new ListaLigada();
        
        l1.adicionar(10);
        l1.adicionar(20);
        l1.adicionar(30);
        l1.adicionar(40);
        
        System.out.println(l1);
        l1.remover(40);
        System.out.println(l1);
        System.out.println(l1.buscar(20));

        System.out.println("----------------");
        System.out.println("Teste Pilha Dinamica");
        
        Pilha p1 = new PilhaDinamica();
        p1.empilhar(10);
        p1.empilhar(20);
        p1.empilhar(30);
        System.out.println(p1.desempilhar());
        System.out.println(p1.desempilhar());
        System.out.println(p1.desempilhar());
        System.out.println(p1.desempilhar());
        System.out.println(p1.desempilhar());

        System.out.println("----------------");
        System.out.println("Teste Pilha Estatica");
        Pilha p2 = new PilhaEstatica(3);
        p2.empilhar(10);
        p2.empilhar(20);
        p2.empilhar(30);
        System.out.println(p2.desempilhar());
        System.out.println(p2.desempilhar());
        System.out.println(p2.desempilhar());
        System.out.println(p2.desempilhar());
        System.out.println(p2.desempilhar());
    }
}
