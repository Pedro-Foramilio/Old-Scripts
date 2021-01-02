package aula;
//obrigação de sobrepor todos os métodos abstratos da super classe
//arquivo main: MainAula.java
public class Teorica extends Aula {
    
    public Teorica(String descricao) {
        super.setDescricao(descricao);
    }

    @Override
    public String getTipo() {
        return "Teorica";
    }

}
