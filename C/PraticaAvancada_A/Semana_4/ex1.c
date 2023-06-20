#include <stdio.h>
#include <stdlib.h>

int ultima_ocorrencia(char *, char);
char* inverte(char *);
int get_len(char *);

int main(void)
{
    char *str = "abcdabcdabcdabcd";
    char *retorno;

    printf("%d\n", ultima_ocorrencia(str, 'l'));
    printf("%d\n", get_len("abcd"));
    retorno = inverte("abcd");
    printf("%s %d\n", retorno, get_len(retorno));

    free(retorno);
    return 0;
}

int ultima_ocorrencia(char *s, char c)
{
    int index = -1;
    int counter = 0;
    char current = s[0];

    while (current != '\0')
    {
        if (current == c) index = counter;
        counter++; 
        current = s[counter];
    }

    return index;
}

int get_len(char *s)
{
    int counter = 0;
    char current = s[0];
    while (current != '\0')
    {
        counter++;
        current = s[counter];
    }
    return counter;
}


char* inverte(char *s)
{
    int len = get_len(s);
    char *s_inverted = (char *)malloc(sizeof(char) * (len + 1));
    int counter = 0;

    for(int i = len-1; i >= 0; i--)
    {
        s_inverted[i] = s[counter];
        counter++;
    }
    s_inverted[len] = '\0';
    return s_inverted;
}
