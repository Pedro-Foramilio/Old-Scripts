/*
Implemente a função logaritmo, que recebe um valor x e um valor n. A função deve calcular o valor de ln(x) usando n termos da série Maclaurin, conforme fórmula a seguir.

ln(1+x) = x - x^2(1/2) + x^3(1/3) - x^4(1/4)...

O valor de x está na faixa (0, 2]. Nesta fórmula, x deve estar na faixa (-1, +1].


Observação: não utilize math.h e não use vetor.

A função deve seguir o seguinte protótipo:

double logaritmo(double x, int n);

Importante: submeta apenas a função. Não inclua o main, não use printf/puts, math.h e vetor.
*/

//#include "logaritmo.h"

double potencia(double base, double expoente) {
    double retorno = 1;
    for (int i = 0; i < expoente; i++) {
        retorno = (double) retorno * base;
    }
    return retorno;
}

double logaritmo(double x, int n) {
    double resultado = x;

    for (int i=1; i < n; i++) {
        resultado += potencia(-1, i) * potencia(x, (i+1)) * (1/((float) (i+1)) ); 
    }

    return resultado;
    
}

