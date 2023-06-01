#include <stdio.h>

double serie(int);

int main()
{
	int n = 0;
	scanf("%d", &n);

	double result = serie(n);
	printf("%.3f\n", result);

	return 0;
}

double serie(int n)
{
	if (n == 0) return 0;

	double result = 0;
	
	for (int i = 1; i <= n; i++)
	{
		result = result + (1/(double)i);
	}
	return result;
}

