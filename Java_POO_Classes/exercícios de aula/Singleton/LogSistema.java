package Singleton;
import java.util.ArrayList;

public class LogSistema {
    private static LogSistema instanciaUnica;
    private ArrayList<String> registros;

    private LogSistema() { //assim apenas a propria classe consegue dar um new
        registros = new ArrayList<String>();
    }

    public static LogSistema getInstanciaUnica() {
        if (instanciaUnica == null) {
            instanciaUnica = new LogSistema();
        }
        return instanciaUnica;
    }

    public void registrar(String evento) {
        registros.add(evento);
    }

    public void imprimir() {
        for (String e: registros) {
            System.out.println(e);
        }
    }
}
