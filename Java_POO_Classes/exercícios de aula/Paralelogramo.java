public class Paralelogramo {
    private int tamanhoLadoA = 0;
    private int tamanhoLadoB = 0;
    private String tipo;
    //lados opostos são paralelos.. a1 // a2 e b1 // b2
    public Paralelogramo(int tamanhoLadoA){
        this.tamanhoLadoA = tamanhoLadoA;
        this.tipo = "quadrado";
    }

    public Paralelogramo(int tamanhoLadoA, int tamanhoLadoB){
        this.tamanhoLadoA = tamanhoLadoA;
        this.tamanhoLadoB = tamanhoLadoB;
        if (tamanhoLadoA != tamanhoLadoB){
            this.tipo = "retangulo";
        }
        else{
            this.tipo = "quadrado";
        }
    }

    public int getArea(){
        if (tipo == "quadrado"){
            return tamanhoLadoA * tamanhoLadoA;
        }
        if (tipo == "retangulo"){
            return tamanhoLadoA * tamanhoLadoB;
        }
        return 0;
    }

    public String getTipo(){
        return "Paralelogramo " + this.tipo;
    }
}
