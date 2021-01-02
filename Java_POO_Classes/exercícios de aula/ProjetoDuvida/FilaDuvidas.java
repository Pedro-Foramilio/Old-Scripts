package ProjetoDuvida;

public class FilaDuvidas<T extends Duvida> extends Fila<T> {

    private String professor;

    public FilaDuvidas(String professor) {
        this.professor = professor;
    }

    public String getProfessor() {
        return this.professor;
    }
    
}
