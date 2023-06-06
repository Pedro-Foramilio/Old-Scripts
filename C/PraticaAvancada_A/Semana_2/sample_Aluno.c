#include <stdio.h>
#include <stdlib.h>

struct aluno
{
	int mat;
	char nome[81];
	char end[121];
	char tel[21];
};
typedef struct aluno Aluno;
#define MAX 100;

void inicializa(int n, Aluno **tab)
{
	int i;
	for (i = 0; i < n; i++)
	{
		tab[i] = NULL;
	}
	return;
}

/* recebe posicao onde dados sao armazenados
 * se posicao vazia, alocar
 * se nao, atualizar
 */
void preenche(int n, Aluno** tab, int i)
{
	if (i<0 || i>=n)
	{
		exit(1);
	}

	if (tab[i] == NULL)
	{
		tab[i] = (Aluno *)malloc(sizeof(Aluno));
	}
	printf("Entre com a matricula:\n");
	scanf("%d", &tab[i]->mat);
}

void retira (int n, Aluno** tab, int i)
{
	if (i < 0 || i >= n) exit(1);

	if (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
}

