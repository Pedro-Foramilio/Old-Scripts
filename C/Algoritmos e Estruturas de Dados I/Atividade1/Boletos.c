#include <stdio.h>
#include <stdlib.h>

typedef struct Boleto Boleto;
struct Boleto
{
    char banco[51];
    char cedente[51];
    char sacado[51];
    double valorDocumento;
    int diaVencimento;
    int diaPagamento;
    double multa;
    double valorFinalPago;
};

double determinaValorFinalPago(Boleto);

void insertion_sort(Boleto *, int );

void imprimirLista(Boleto *, int);

int main()
{
    int nBoletos;
    scanf("%d", &nBoletos);

    Boleto *listaBoletos = (Boleto *) malloc(nBoletos  * sizeof(Boleto));

    for (int i = 0; i < nBoletos; i++)
    {
        scanf("%s", listaBoletos[i].banco);
        scanf("%s", listaBoletos[i].cedente);
        scanf("%s", listaBoletos[i].sacado);
        scanf("%lf", &listaBoletos[i].valorDocumento);
        scanf("%d", &listaBoletos[i].diaVencimento);
        scanf("%d", &listaBoletos[i].diaPagamento);
        scanf("%lf", &listaBoletos[i].multa);
        listaBoletos[i].valorFinalPago = determinaValorFinalPago(listaBoletos[i]);   
    }
    insertion_sort(listaBoletos, nBoletos);
    imprimirLista(listaBoletos, nBoletos);

    free(listaBoletos);
    return 0;
}

void insertion_sort(Boleto *v, int n) {
    int i, k;
    for (i = 1; i < n; i++) { //considera o i = 0 como já ordenado

        Boleto item_atual = v[i]; //guarda elemento atual

        //encontra indice para inserção e desloca elementos para a direita
        int indice_para_inserir = i;
        //ordem crescente: item_atual > v[k]
        for (k = i-1; k >= 0 && item_atual.valorFinalPago < v[k].valorFinalPago ; k--) {
            v[k+1] = v[k];
            indice_para_inserir--;
        }

        v[indice_para_inserir] = item_atual;
    }
        
    return;
}

double determinaValorFinalPago(Boleto instancia)
{
    double valorFinal = instancia.valorDocumento;
    double multa = instancia.multa;
    int diasAtraso;

    if (instancia.diaPagamento > instancia.diaVencimento)
    {
        diasAtraso = instancia.diaPagamento - instancia.diaVencimento;
        valorFinal = valorFinal + multa * ((double)diasAtraso);
    }
    return valorFinal;
}

void imprimirLista(Boleto *b, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        printf("%s %s %s %.2lf\n", 
            b[i].sacado, b[i].cedente, b[i].banco, b[i].valorFinalPago);
    }
}
