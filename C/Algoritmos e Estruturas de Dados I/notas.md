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
        ```
---

## Algoritmos de Ordenação

- **Problema da Ordenação**
    Suponha uma colecao de V elementos de n elementos, deseja-se que V tenha a seguinte propriedade:
    ```v_j <= v_j+1, 0 <=j < n-1, para todo v_j pertecente a V```

- **Bubble Sort**
    Mecanismo:
        - Compara-se os n elementos do vetor, dois a dois
        - Trocando de posição quando o i-esimo elemento for maior que o (i+1)-esimo elemento
        - Repete-se para os n-1 elementos restantes
        - Repete-se para os n-2 elementos restantes
        - Ate que reste so 1 elemento 
    
    Eficiencia:
        T(n) = (n^2 - n) /2
        Ordem: O(n^2)
    
    ```c
    void bubbleSort(int *v, int n)
    {
        int i, j, aux;
        for (i=0; i<n-1; i++)
        {
            for (j=0; j< n-1-i; j++)
            {
                if (v[j] > v[j+1])
                {
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }
    }
    ```

- **Selection Sort**
    Ordena um vetor baseado em localizar o menor elemento e posiciona-lo na primeira posicao.
    Entao encontra o segundo menor e coloca na segunda posicao, so on and so forth.

    Eficiencia identica ao Bubble Sort do ponto de vista matematico, mas tende a consumir sensivelmente menos tempo devido a menor quantidade de trocas, se comparado ao numero de trocas que ocorrem em BubbleSort, o que também impacta atribuicoes de variaveis

    No pior caso, bubble faz (n^2 - n) /2 comparacoes e (n^2 - n) /2 trocas.

    Ja o selection faz (n^2 - n) /2 comparacoes mas so faz trocas depois de encontrar o menor elemento, realizando n-1 trocas. Assim o numero de operacoes e menor no SelectionSort

    ```c
    void selectionSort(int *v, int n)
    {
        int i, j, aux, iMin;
        for (i=0; i<n-1; i++)
        {
            for (j=i+1, iMin = i; j<n; j++)
            {
                if (v[j] < v[iMin])
                    iMin = j;
            }

            aux= v[i];
            v[i] = v[iMin];
            v[iMin] = aux;
        }
    }
    ```
- **Inserion Sort**
    Eficiente para ordenar pequena quantidade de elementos. Insere cada elemento no lugar apropriado
    
    Percorre o elemento da esquerda pra direita deixando os elementos mais a esqueda sempre ordenados

    Facil Implementacao, com ineficiencia pra entradas suficientemente grandes

    ```c
    void insertionSort(int *v, int n)
    {
        int chave, i, j;
        for (i = 1; i < n; i++)
        {
            chave = vetor[i];
            j = i-1;
            while(j>=0 && vetor[j] >= chave)
            {
                vetor[j+1] = vetor[j];
                vetor[j] = chave;
                j--;
            }
        }
    }
    ```
    