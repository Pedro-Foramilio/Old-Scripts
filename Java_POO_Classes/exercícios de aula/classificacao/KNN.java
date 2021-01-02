package classificacao;
/*
class Exemplo {
    private double[] atributos;

    Exemplo(double[] atributos) {
        this.atributos = atributos.clone();
    }
    
    double[] getAtributos() {
        return this.atributos;
    }
}


class ExemploComRotulo extends Exemplo {
    private int rotulo;

    ExemploComRotulo(double[] atributos, int rotulo) {
        super(atributos);
        this.rotulo = rotulo;
    }

    int getRotulo() {
        return this.rotulo;
    }
}

*/
public class KNN {
    private int k;
    private ExemploComRotulo[] dados; //conjunto de exemplos de treinamento

    private static double calculaDistancia (double[] dadosX, double[] dadosY) throws ExcecaoExemploInvalido { 
        
        // x = treinamento, y = teste
        double distancia = 0.0;
        if (dadosX.length != dadosY.length) {
            throw new ExcecaoExemploInvalido(dadosX.length, dadosY.length);
        }

        int tamanho = dadosX.length;

        double aux = 0;
        for (int i=0; i < tamanho; i++) {
            aux += Math.pow( dadosX[i] - dadosY[i], 2.0 );
        }

        distancia = Math.sqrt(aux);
        return distancia;
    }

    private static double[][] ordenador(double[][] vetorr) {
        double[][] vetor = vetorr;
        boolean ordenado = false;
        double temp;
        while ( !ordenado ) {
            ordenado = true;
            for (int i=0; i < vetor.length-1; i++) {
                if (vetor[i][0] > vetor[i+1][0]) {
                    temp = vetor[i][0];
                    vetor[i][0] = vetor[i+1][0];
                    vetor[i+1][0] = temp;
                    ordenado = false;
                }
            }
        }
        return vetor;
    }

    private static double[][] menoresDistancias(double[][] distancias, int k) {
        double[][] vetorAuxiliar = ordenador(distancias);
        double[][] kDistancias = new double[k][2];
        for (int i=0; i < k; i++) {
            kDistancias[i][0] = vetorAuxiliar[i][0];
            kDistancias[i][1] = vetorAuxiliar[i][1];
        }
        return kDistancias;
    }

    public KNN(int k) {
        this.k = k;
    }

    public void setDadosTreinamento(ExemploComRotulo[] dados) throws Exception{
        if (dados.length < this.k) 
            throw new Exception("Poucos dados de treinamento");
        else {
            this.dados = dados;
        }
    }


    public int predizer(Exemplo teste) throws Exception, ExcecaoExemploInvalido {

        if (this.dados == null) {
            throw new Exception("Dados de treinamento - nao inicializado");
        }
/*
        else if (teste.getAtributos().length != dados.length) {
            throw new ExcecaoExemploInvalido(dados.length, teste.getAtributos().length);
        }
*/
        else {
            /* 
            montando matriz [distancia][rotulo]
                distancia[0][0], rotulo[0][1]
                distancia[1][0], rotulo[1][1]
            */
            int nDistancias = this.dados.length;
            double[][] distancias = new double[nDistancias][2];
            for (int i=0; i < nDistancias; i++) {
                double aux = 0;
                double[] treinamento = this.dados[i].getAtributos();
                aux = calculaDistancia(treinamento, teste.getAtributos());
                distancias[i][0] = aux;
                distancias[i][1] = this.dados[i].getRotulo();
            }

            double[][] kMenoresDistancias = menoresDistancias(distancias, this.k);

            //[0][0] => Rotulo, [0][1] => contador...
            double[][] contadores = new double[kMenoresDistancias.length][2];
            for (int i=0; i < kMenoresDistancias.length; i++) {
                contadores[i][0] = kMenoresDistancias[i][1]; //contador[i] = rotuloKmenor (kmenor[i][1])
                contadores[i][1] = 0;
            }

            //contando quantas vezes o rotulo aparece
            for (int i=0; i < kMenoresDistancias.length; i++) {
                for (int j=0; j < contadores.length; j++) {
                    if (kMenoresDistancias[i][1] == contadores[j][0]) {
                        contadores[j][1]++;
                    }
                }
            }

            //determinando o indice que tem o maior rotulo
            int indiceMaximo = 0;
            for (int i=0; i < contadores.length; i++) {
                if (contadores[i][1] > contadores[indiceMaximo][1]) {
                    indiceMaximo = i;
                }
            }

            return (int) contadores[indiceMaximo][1];
        }
    }
}
