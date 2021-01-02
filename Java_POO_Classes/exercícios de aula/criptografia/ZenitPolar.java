package criptografia;

public class ZenitPolar implements Cifra{

    @Override
    public String cifrar(String mensagem) {
        String output = "";
        for (int i = 0; i < mensagem.length(); i++) {
            char c = mensagem.charAt(i);
            if (c == 'z') {
                output += "p";
                continue;
            }
            if (c == 'p') {
                output += "z";
                continue;
            }
            if (c == 'e') {
                output += "o";
                continue;
            }
            if (c == 'o') {
                output += "e";
                continue;
            }
            if (c == 'n') {
                output += "l";
                continue;
            }
            if (c == 'l') {
                output += "n";
                continue;
            }
            if (c == 'i') {
                output += "a";
                continue;
            }
            if (c == 'a') {
                output += "i";
                continue;
            }
            if (c == 't') {
                output += "r";
                continue;
            }
            if (c == 'r') {
                output += "t";
                continue;
            }
            output += c;
        }
        return output;
    }

    @Override
    public String decifrar(String mensagem) {
        return cifrar(mensagem);

    }
}
