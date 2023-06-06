#include <stdio.h>

int coreAlg(int);
int isEven(int);
int cycleLen(int);
int maxCycleLen(int, int);

int main()
{
	int i = 0;
	int j = 0;
	while(scanf("%d %d", &i, &j) != EOF)
	{
		if (i == 0 || j ==0) break;
		printf("%d %d %d\n", i, j, maxCycleLen(i, j));
	}

    return 0;
}

int isEven(int n)
{
    return (n % 2) == 0;
}

int coreAlg(int n)
{
	if(isEven(n))
	{
		return n/2;
	}
	
	return 3*n + 1;	
}

int cycleLen(int n)
{
	int cycle_count = 1;
	while (n > 1)
	{
		cycle_count++;
		n = coreAlg(n);
	}
	return cycle_count;
}

int maxCycleLen(int i, int j)
{
	if (i > j)
	{
		int temp = i;
		i = j;
		j = temp;
	}

	int max_cycle = cycleLen(i);

	i++;
	while( i <= j)
	{
		int iter_cycle_len = cycleLen(i);
		max_cycle = (iter_cycle_len > max_cycle) ? iter_cycle_len : max_cycle;
		i++;
	}

	return max_cycle;
}

