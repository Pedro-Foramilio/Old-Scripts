# Algumas Notas de Aula

## Análise de Algoritmos e Algoritmos de Busca

- **Problema da Busca**
    Formalmente, suponha uma cole'cao ```V``` de elementos de tamanho ```n``` e um elemento ```x``` qualquer. Averiguar se ```x = V_i``` onde 0<= i < n

- **Busca Linear**
    Quantidade de comparacoes aumenta linearmente. O(n)
    ```c
    int busca(int *v, int n, int x)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (v[i] == x)
                return i;
        }
        return -1;
    }
    ```
    - Busca Linear Recursiva
        Caso base: encontra ou acaba o espaco de busca
        ```c
        int busca(int *v, int n, int x)
        {
            if (n < 1) return -1;
            if (v[n-1] == x) return n-1;
            return busca(v, n-1, x)
        }
        ```
- **Busca Binária**
    PREMISSA: lista de elementos esta ordenada - O(log2 (n))
    ```c
    int buscaBin(int *v, int n, in x)
    {
        int esq=0, dir=n-1, meio;
        while(esq <= dir)
        {
            meio = (esq+dir)/2;
            if (v[meio] == x)
                return meio;
            else if (v[meio] > x)
                dir = meio - 1;
            else
                esq = meio+1
        }
        return -1;
    }
    ```
    - Busca Linear Recursvia:
        ```c
        int buscaBin(int *v, int esq, int dir, int x)
        {
            int meio;

            if (esq <= dir)
            {
                meio = (esq + dir)/2;
                if (v[meio] == x)
                    return meio;
                else if (v[meio] > x)
                    return buscaBin(v, esq, meio-1, x);
                else
                    return buscaBin(v, meio+1, dirm x);
            }

            return -1;
        }
