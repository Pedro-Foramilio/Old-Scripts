
public class Auxiliar {

    static double[] ordenar(double a[]) {
        boolean sorted = false;
        double temp;
        while ( !sorted ) {
            sorted = true;
            for (int i=0; i < a.length-1; i++) {
                if (a[i] > a[i+1]) {
                    temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    sorted = false;
                }
            }
        }
        return a;
    }

    public static void main(String[] args){

        
        System.out.println("------------");
        String[][] vetor = new String[2][2];
        vetor[0][0] = "00";
        vetor[0][1] = "01";
        vetor[1][0] = "10";
        vetor[1][1] = "11";
        for (int i=0; i < 2; i++) {
            for (int j=0; j < 2; j++) {
                System.out.print("Vetor[" + i + "][" + j + "] = " + vetor[i][j] + " ");
            }
            System.out.println();
        }

        /*
        Conjunto c = new Conjunto();
        c.adicionar(1);
        c.adicionar(2);
        c.adicionar(3);
        c.adicionar(4);
        c.adicionar(5);
        System.out.println(c.getQtd());
        System.out.println(c);
        c.remover(4);
        System.out.println(c.getQtd());
        System.out.println(c);
        System.out.println(c.buscar(2));
        
        System.out.println("Testando Uniao");
        System.out.println("Cojunto c1:");
        System.out.println(c);
        Conjunto c2 = new Conjunto();
        c2.adicionar(10);
        c2.adicionar(20);
        c2.adicionar(3);
        c2.adicionar(40);
        System.out.println("Cojunto c2:");
        System.out.println(c2);
        System.out.println("Uniao de c1 com c2:");
        System.out.println(Conjunto.uniao(c, c2));
        System.out.println("-------------------------");
        System.out.println("Teste Intersecao");
        Conjunto c3 = new Conjunto();
        c3.adicionar(17);
        c3.adicionar(16);
        c3.adicionar(15);
        c3.adicionar(14);
        Conjunto c4 = new Conjunto();
        c4.adicionar(12);
        c4.adicionar(13);
        c4.adicionar(14);
        c4.adicionar(15);
        System.out.println("Cojunto c3:");
        System.out.println(c3);
        System.out.println("Cojunto c4:");
        System.out.println(c4);
        System.out.println("Intersecao:");
        System.out.println(Conjunto.intersecao(c3, c4));
        System.out.println("-------------------------");
        System.out.println("Conjunto.intersecao({20 15}, {60 70 20})");
        Conjunto a = new Conjunto();
        Conjunto b = new Conjunto();
        a.adicionar(20);
        a.adicionar(15);
        b.adicionar(60);
        b.adicionar(70);
        b.adicionar(20);
        System.out.println(Conjunto.intersecao(a, b));
        */
    }
}
