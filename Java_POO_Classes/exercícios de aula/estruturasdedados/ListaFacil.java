package estruturasdedados;

public class ListaFacil {
    
    private int[] itens;
    private int indicieUltimo = -1;

    public void iniciaLista(int tamanhoMax){
        this.itens = new int[tamanhoMax];
    }

    public void adicionarItem(int novoItem){
        if (indicieUltimo + 1 >= itens.length){
            System.out.println("Limite Atingido");
            return;
        }
        itens[++indicieUltimo] = novoItem;

    }

    public Integer lerItem(int indicie){
        if (indicie >= 0 && indicie <= indicieUltimo){
        return itens[indicie];
        }
        else{
            System.out.println("Indicie invalido");
            return null;
        }
    }
}
