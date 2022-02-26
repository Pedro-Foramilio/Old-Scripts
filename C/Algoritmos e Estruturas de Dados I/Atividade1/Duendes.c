#include <stdio.h>

int main()
{
    int tempoRestante, p1, p2;
    scanf("%d %d %d", &tempoRestante, &p1, &p2);
    printf("%s\n", tempoRestante >= (p1 + p2) ? "Farei hoje!" : "Deixa para amanha!");
    return 0;
}
