package Singleton;

public class Programa {
    public static void main(String[] args) {
        LogSistema.getInstanciaUnica().registrar("Inicio");
        LogSistema.getInstanciaUnica().registrar("Evento 1");
        LogSistema.getInstanciaUnica().registrar("Evento 2");
        LogSistema.getInstanciaUnica().registrar("Finalizar");

        LogSistema.getInstanciaUnica().imprimir();
    }
}
