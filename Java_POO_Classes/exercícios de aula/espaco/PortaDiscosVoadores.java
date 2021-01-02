package espaco;
// é possivel usar a classe sem importar pq tao no mesmo package, só se usa import quando esta em diferentes packages
public class PortaDiscosVoadores {
    private DiscoVoador[] discos = new DiscoVoador[3];

    private int obterIndiceParaInserir(){
        for (int i= 0; i< discos.length; i++){
            if (discos[i] == null) return i;
        }
        return -1; //indice invalido
    }

    public void guardarDisco(DiscoVoador disco){
        int indice = obterIndiceParaInserir();
        if (indice == -1){
            System.out.println("Vetor cheio.");
        }
        else{
            discos[indice] = disco;
        }
    }

    public DiscoVoador liberarDisco(int indice){
        if (indice >= 0 && indice < discos.length){
            DiscoVoador disco = discos[indice];
            discos[indice] = null;
            return disco;
        }
        else{
            System.out.println("liberarDisco: indice invalido");
            return null;
        }
    }
}
