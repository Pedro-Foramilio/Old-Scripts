#include <stdio.h>
#include <stdlib.h>

typedef struct Lista Lista;
struct Lista {
    int max_size;
    int current_size;
    int pos_first;
    int pos_last;
    char *vetor;
};

Lista *iniciarLista()
{
    Lista *q = (Lista *) malloc(sizeof(Lista));
    q->max_size = 2;
    q->current_size = 0;
    q->pos_first = 0;
    q->pos_last = -1;
    q->vetor = (char *)malloc(sizeof(char) * 2);
    
    return q;
    
}

void inserir(Lista *q, char a)
{
    int space_avb = q->max_size - q->current_size;
    
    if (space_avb == 1)
    {
        q->vetor = realloc(q->vetor, sizeof(char) * 2 * q->max_size);
        q->max_size = 2 * q->max_size;
    }

    int insert_position = q->pos_last + 1;
    if (insert_position == q->max_size)
    {
        insert_position = 0;
    }
    
    q->vetor[insert_position] = a;
    q->pos_last = insert_position;
    q->current_size = (q->current_size) + 1;
}

void remover(Lista *q)
{
    if (q->current_size == 0) return;
    
    q->vetor[q->pos_first] = '\0';
    if (q->pos_first == q->max_size - 1)
    {
        q->pos_first = 0;
    }
    else
    {
        q->pos_first = q->pos_first + 1;
    }

    q->current_size = q->current_size - 1;
    
    int space_avb = q->max_size - q->current_size;
    if (space_avb >= 3*(q->max_size/4))
    {
        char *new_v = (char *)malloc(sizeof(char)*(q->max_size/2));
        int aux = 0;

        if (q->pos_first <= q->pos_last)
        {
            for (int i = q->pos_first; i <= q->pos_last; i++)
            {
                new_v[aux] = q->vetor[i];
                aux++;
            }
        }

        else
        {
            for (int i = q->pos_first; i < q->max_size; i++)
            {
                new_v[aux] = q->vetor[i];
                aux++;
            }
            for (int i = 0; i <= q->pos_last; i++)
            {
                new_v[aux] = q->vetor[i];
                aux++;
            }
        }

        free(q->vetor);
        q->vetor = new_v;
        q->max_size = q->max_size/2;
        q->pos_first = 0;
        q->pos_last = aux-1;
    }
}

void imprimir(Lista *q)
{
    int i;
    printf("index :  ");
    for (i = 0; i < q->max_size; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
    printf("content:");

    for (i = 0; i < q->max_size - 1; i++)
    {
        char c = q->vetor[i];
        if (c == '\0')
        {
            printf(" . ");
        }
        else
        {
            printf(" %c ", c);
        }
    }
    char c = q->vetor[q->max_size - 1];
    if (c == '\0')
    {
        printf(" .");
    }
    else
    {
        printf(" %c", c);
    }

    printf("\n");
    printf("         H: %d T: %d\n\n", q->pos_first, (q->pos_last+1)%q->max_size);
    return;
}

int main()
{
    //ABCD--E--
    Lista *q = iniciarLista();
    char ops[100];
    while (scanf("%s", ops) != EOF)
    {
        int i = 0;
        char op = ops[0];
        while (op != '\0')
        {
            if (op == '-')
            {
                printf("dequeued %c\n", q->vetor[q->pos_first]);
                remover(q);
            } 
            else
            {
                printf("enqueued %c\n", op);
                inserir(q, op);
            } 
                imprimir(q);
            op = ops[++i];
        }
    }
    
    free(q->vetor);
    free(q);
    return 0;
}
