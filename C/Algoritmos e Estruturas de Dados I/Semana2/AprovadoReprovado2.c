#include <stdio.h>

float media(float x, float y)
{
    return (x + y) / (float) 2.0;
}

char * situacaoFinal(float media)
{
    if(media >= 60.0)
    {
        return "APROVADO";
    } else if (media >= 40)
    {
        return "EXAME FINAL";
    } else
    {
        return "REPROVADO";
    }
}

int main()
{
    float nota1, nota2;
    scanf("%f %f", &nota1,&nota2);

    printf("%s\n", situacaoFinal(media(nota1, nota2)));    

    return 0;
}
