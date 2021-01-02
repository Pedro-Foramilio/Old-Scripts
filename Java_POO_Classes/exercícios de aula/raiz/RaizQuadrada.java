package raiz;

public class RaizQuadrada {
    
    public static double calcular(double n) throws ExcecaoRaizNegativa {
        if (n >= 0) {
        double raiz = Math.sqrt(n);
        return raiz;
        }
        else {
            double parteComplexa = (-1) * n;
            throw new ExcecaoRaizNegativa(parteComplexa);
        }
    }

}
