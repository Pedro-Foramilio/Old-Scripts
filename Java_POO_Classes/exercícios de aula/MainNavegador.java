import navegador.*;

public class MainNavegador {
    public static void main(String[] args) {
        Navegador nav = new Navegador(3);

        
        
        AbaNavegador aba0= nav.abrirAba(1, "Buscador_A");
        AbaNavegador aba1= nav.abrirAba(2, "RedeSocial_A");
        AbaNavegador aba2= nav.abrirAba(1, "Buscador_B");
        
        System.out.println(aba1.getTitulo());
        System.out.println(aba1.getTipo());
        
        
       
        ((AbaBuscador)aba0).buscar("Programacao");
        ((AbaBuscador)aba2).buscar("orientada");
        ((AbaBuscador)aba0).buscar("objetos");
        ((AbaRedeSocial)aba1).postar("post 1");
        ((AbaRedeSocial)aba1).postar("post 2");
        ((AbaBuscador)aba0).buscar("testes");
        
        System.out.println("------Abas------");
        for(String s: nav.getAbas())System.out.println(s);
        
        System.out.println("------Historico------");
        for(String s : nav.getHistorico()){
            System.out.println(s);
        } 
        
        nav.fecharAba(aba1);
        nav.getAbas();
        
        System.out.println("------Historico------");
        for(String s : nav.getHistorico()){
            System.out.println(s);
        } 
        
        AbaNavegador aba3= nav.abrirAba(2, "RedeSocial_B");
        ((AbaRedeSocial)aba3).postar("post 2");
        ((AbaRedeSocial)aba3).postar("post 3");
        ((AbaRedeSocial)aba3).postar("post 4");
        ((AbaBuscador)aba2).buscar("navegador");
        
        nav.fecharAba(aba0);
        System.out.println("------Abas------");
        for(String s: nav.getAbas())System.out.println(s);
        
        System.out.println("------Historico------");
        for(String s : nav.getHistorico()){
            System.out.println(s);
        } 
        
        
        
        
    }
}
