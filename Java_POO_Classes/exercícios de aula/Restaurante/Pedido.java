package Restaurante;
import java.util.ArrayList;
public class Pedido {
    private Mesa mesa;
    private Garcom garcom;
    private ArrayList<Prato> pratos = new ArrayList<Prato>();
        
    public Pedido(Mesa mesa, Garcom garcom) {
        this.mesa = mesa;
        this.garcom = garcom;
    }

    public void incluirPrato(Prato prato){
        pratos.add(prato);
    }

    public void imprimirPedido(){
        for (Prato prato : pratos) {
            System.out.println(prato.nome);
            System.out.println(prato.preco);
            
        }
    }

    public void fechar(){
        double total = 0.0;
        System.out.println(mesa.numero);
        System.out.println(garcom.nome);
        for (Prato prato : pratos) {
            System.out.println(prato.nome);
            total += prato.preco;
        }
        System.out.println(total);
    }

   
}
