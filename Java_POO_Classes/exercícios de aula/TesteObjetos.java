import estruturasdedados.ListaFacil;
import espaco.DiscoVoador;
import espaco.PortaDiscosVoadores;

public class TesteObjetos {
    public static void main(String[] args){
        ListaFacil lista = new ListaFacil();
        lista.iniciaLista(3);
        lista.adicionarItem(11);
        lista.adicionarItem(22);
        lista.adicionarItem(33);
        lista.adicionarItem(44);
        lista.adicionarItem(55);
        System.out.println("Teste ListaFacil\n");
        System.out.println(lista.lerItem(0));
        System.out.println(lista.lerItem(1));
        System.out.println(lista.lerItem(2));
        System.out.println(lista.lerItem(3));
        System.out.println("-------------");
        System.out.println("Teste espaco\n");
        DiscoVoador d1 = new DiscoVoador();
        DiscoVoador d2 = new DiscoVoador();
        DiscoVoador d3 = new DiscoVoador();
        DiscoVoador d4 = new DiscoVoador();
        d1.setTipo("A");
        d2.setTipo("B");
        d3.setTipo("C");
        d4.setTipo("D");

        PortaDiscosVoadores portaDiscos = new PortaDiscosVoadores();
        portaDiscos.guardarDisco(d1);
        portaDiscos.guardarDisco(d2);
        portaDiscos.guardarDisco(d3);
        portaDiscos.guardarDisco(d4); //erro
        for (int i=0; i<4; i++){
            DiscoVoador disco = portaDiscos.liberarDisco(i);
            if (disco != null) disco.darPartida();
        }
        
    }
    
}
