package plano;

public class PlanoDeAulas {
    
    private int indiceUltimaAula;
    private Aula[] listaDeAulas;
    
    public PlanoDeAulas(int qtdAulas) {
        this.listaDeAulas = new Aula[qtdAulas];
        this.indiceUltimaAula = -1;
    }

    //implementacao de construtor de copia
    public PlanoDeAulas(PlanoDeAulas plano) {
        this.indiceUltimaAula = plano.indiceUltimaAula;
        this.listaDeAulas = new Aula[plano.listaDeAulas.length];
        for (int i=0; i < this.indiceUltimaAula; i++) {
            this.listaDeAulas[i] = plano.listaDeAulas[i]; // aqui ocorre copia das REFERENCIAS de cala Aula
        }
    }

    public void adicionarAula(Aula novaAula) throws TemMuitaAula, RevisaoNaoPermitida {
        if (novaAula == null) throw new AulaNula();

        if (novaAula instanceof AulaRevisao) {
            throw new RevisaoNaoPermitida();
        }

        if (this.indiceUltimaAula + 1 >= listaDeAulas.length) {
            throw new TemMuitaAula(listaDeAulas.length, novaAula);
        }

        this.listaDeAulas[++indiceUltimaAula] = novaAula;
    }

    public void imprimir() {
        System.out.println("----Aulas----");
        for (Aula elemento : this.listaDeAulas) {
            if (elemento != null){
                System.out.println("- [" + elemento.getTipo() +"] " + elemento.getDescricao());
            }
        }
    }

    public void imprimirFormulaAvaliacao() {
        String formula = "";

        for (Aula elemento : this.listaDeAulas) {
            if (elemento != null && elemento instanceof Avaliacao) {
                if (! formula.equals("")) formula += " + ";

                formula += ((Avaliacao) elemento).getPeso(); //casting para enxergar elemento como Avaliacao
                formula += " x " + elemento.getDescricao();
            }
        }
        System.out.println("Avaliacao = " + formula);
    }

}
