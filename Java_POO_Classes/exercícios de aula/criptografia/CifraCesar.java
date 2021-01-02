package criptografia;

public class CifraCesar implements Cifra{
    private int n;

    public CifraCesar(int n){
        this.n = n;
    }

    @Override
    public String cifrar(String mensagem) {
        String output = "";

        for (int i=0; i < mensagem.length(); i++) {
            char c_atual = mensagem.charAt(i);
            char c_cifrado;

            if (c_atual >= 97 && c_atual <= 122) {
                c_cifrado = (char) ((c_atual - 97 + this.n)%26 + 97);
            }
            else if (c_atual >= 65 && c_atual <= 90) {
                c_cifrado = (char) ((c_atual - 65 + this.n)%26 + 65);
            }
            else {
                c_cifrado = c_atual;
            }
            output += c_cifrado;
        }
        return output;
    }

    @Override
    public String decifrar(String mensagem) {
        String output = "";

        for (int i=0; i < mensagem.length(); i++) {
            char c_atual = mensagem.charAt(i);
            char c_cifrado;

            if (c_atual >= 97 && c_atual <= 122) {
                c_cifrado = (char) ((c_atual - 97 + (26 - this.n))%26 + 97);
            }
            else if (c_atual >= 65 && c_atual <= 90) {
                c_cifrado = (char) ((c_atual - 65 + (26 - this.n))%26 + 65);
            }
            else {  
                c_cifrado = c_atual;
            }
            output += c_cifrado;
        }
        return output;
    }
}
