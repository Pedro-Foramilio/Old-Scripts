package autocorrecao;

public class Alternativa implements Cloneable {
    private String descricao;

    public Alternativa(String descricao){
        this.setDescricao(descricao);
    }
    
    private void setDescricao(String descricao){
        this.descricao = descricao;
    }

    public String getDescricao(){
        return this.descricao;
    }

    @Override //shallow copy, mas como nao há opjetos, shallow copy = deep copy
    public Alternativa clone() throws CloneNotSupportedException {
        return (Alternativa) super.clone();
    }
}
