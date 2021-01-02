package navegador;

public class Navegador {
    private int limiteAbas;
    protected static String[] historico = new String[100];
    protected AbaNavegador[] lista_abas;
    protected int quantidadeAbasAbertas;

    public Navegador(int limiteAbass) {
        this.limiteAbas = limiteAbass;
        lista_abas = new AbaNavegador[limiteAbass];
        quantidadeAbasAbertas = 0;
    }

    public AbaNavegador abrirAba(int tipo, String titulo) {

        if (quantidadeAbasAbertas == limiteAbas) return null;

        AbaNavegador aux;
        if (tipo == 1) {
            aux = new AbaBuscador();
            aux.titulo = titulo;
            lista_abas[quantidadeAbasAbertas] = aux;
        }
        else {
            aux = new AbaRedeSocial();
            aux.titulo = titulo;
            lista_abas[quantidadeAbasAbertas] = aux;
        }

        quantidadeAbasAbertas += 1;
        return aux;
    }

    public void fecharAba(AbaNavegador aba) {
        
        for (int i=0; i < this.lista_abas.length; i++) {
            if (aba.equals(this.lista_abas[i])) {
                if (i+1 == quantidadeAbasAbertas) {
                    this.lista_abas[i] = null;
                    break;
                }
                else {
                    for (int j = i; j < quantidadeAbasAbertas-1; j++) {
                        //shifting pra esquerda
                        AbaNavegador aux = this.lista_abas[j+1];
                        this.lista_abas[j+1] = this.lista_abas[j];
                        this.lista_abas[j] = aux;
                    }
                    this.lista_abas[quantidadeAbasAbertas - 1] = null;
                    break;
                }
            }
        }
        quantidadeAbasAbertas -= 1;
    }

    public String[] getAbas() {
        int contador_null = 0;
        for (AbaNavegador elemento : lista_abas) {
            if (elemento == null) contador_null++;
        }

        String[] output = new String[this.limiteAbas - contador_null];
        int aux = 0;
        for (int i=0; i < this.lista_abas.length; i++) {
            if (lista_abas[i] == null) {
                aux++;
                continue;
            }
            String tipo = lista_abas[i].getTipo();
            String titulo = lista_abas[i].getTitulo();
            String out = tipo + " " + titulo;
            output[i-aux] = out;
        }

        return output;
    }

    public String[] getHistorico() {
        int contadorNotNull = 0;
        for (String elemento : historico) {
            if (elemento != null) contadorNotNull++;
        }

        String[] output = new String[contadorNotNull];
        for( int i=0; i < contadorNotNull; i++) {
            output[i] = historico[i];
        }

        return output;
    }
}
