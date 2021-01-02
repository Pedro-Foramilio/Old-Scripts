public class ArquivoTexto implements Cloneable {
    private int nLinhas;
    private String[] texto;

    //copy implementation
    @Override
    public ArquivoTexto clone() throws CloneNotSupportedException {
        return (ArquivoTexto) super.clone();
    }

    public ArquivoTexto(int nLinhas) {
        this.nLinhas = nLinhas;
        this.texto = new String[nLinhas];
        for (int i=0; i < nLinhas; i++) {
            this.texto[i] = (String) "";
        }
    }

    //shallow copy
    public ArquivoTexto criarAtalho() throws CloneNotSupportedException{
        return (ArquivoTexto) this.clone();
    }
    //deep copy
    public ArquivoTexto criarBackup() throws CloneNotSupportedException{
        ArquivoTexto novoArquivo = this.clone();
        novoArquivo.texto = this.texto.clone();
        return novoArquivo;
    }

    public String ler() {
        String output = "";
        for (int i=0; i < texto.length; i++) {
            if (i+1 == texto.length) {
                output += texto[i];
                break;
            }
            else {
                output += texto[i] + "\n";
            }
        }
        return output;
        
    }

    public void modificarLinha(int indiceLinha, String novaString) {
        if (indiceLinha <= nLinhas)
            this.texto[indiceLinha] = novaString;
    }
}
