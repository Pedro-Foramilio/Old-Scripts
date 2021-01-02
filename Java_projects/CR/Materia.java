package CR;


public class Materia {
    private String conceito;
    private int creditos;

    public Materia(String conceito, int creditos) throws Exception{
        if (conceito.toUpperCase().equals("A") || conceito.toUpperCase().equals("B") ||
        conceito.toUpperCase().equals("C") || conceito.toUpperCase().equals("D") ||
        conceito.toUpperCase().equals("F")) {
            this.conceito = conceito.toUpperCase();
            this.creditos = creditos;
        } else {
            throw new Exception("Conceito deve ser um de: A, B, C, D, F");
        }
    }

    public String getConceito() {
        return this.conceito;
    }

    public int getCreditos() {
        return this.creditos;
    }

    public int notaMateria() throws Exception{
        String conceito = getConceito();
        int credito = getCreditos();
        switch(conceito) {
            case "A":
                return 4 * credito;
            case "B":
                return 3 * credito;
            case "C":
                return 2 * credito;
            case "D":
                return 1 * credito;
            case "F":
                return 0;
        }
        throw new Exception("Falha ao poderar nota da materia");
    }

    @Override
    public String toString() {
        return "Creditos: " + this.getCreditos() + ", Conceito: " + this.getConceito();
    }
    
}
