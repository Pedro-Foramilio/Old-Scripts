# Algumas Notas de Aula

## Análise de Algoritmos e Algoritmos de Busca

### Problema da Busca
Formalmente, suponha uma cole'cao ```V``` de elementos de tamanho ```n``` e um elemento ```x``` qualquer. Averiguar se ```x = V_i``` onde 0<= i < n

### Busca Linear
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
- **Busca Linear Recursiva**
    Caso base: encontra ou acaba o espaco de busca
    ```c
        int busca(int *v, int n, int x)
        {
            if (n < 1) return -1;
            if (v[n-1] == x) return n-1;
            return busca(v, n-1, x)
        }
    ```
### Busca Binária
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
- **Busca Linear Recursvia**:
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

# Algoritmos de Ordenação

## Problema da Ordenação
Suponha uma colecao de V elementos de n elementos, deseja-se que V tenha a seguinte propriedade:
    ```v_j <= v_j+1, 0 <=j < n-1, para todo v_j pertecente a V```

## Bubble Sort
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

## Selection Sort
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
## Inserion Sort
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

## Lower Bound do Problema de Ordenação

Ate agora, apreesntamos algoritimos que ordenam n numeros em tempo O(n^2), sendo o upper bound
Desejamos encontar um limite inferior teorico para este problema, a minima complexidade de tempo de quaisquer de suas resolucoes algoritimicas

- Arvore de Comparações
    Qualquer algoritimo de ordenacao baseado em comparacoes pode ser representado em uma arvore binaria.
    Na raiz fica a primeira comparacao realizado entre dois elementos, nos filhos, as comparacoes subsequentes. Assim as *folhas* dessa arvore representam as possiveis *solucoes* do problema.

    A altura da arvore e o numero maximo de comparacoes que o algoritimo realiza (maior ramo), ou seja, seu tempo de pior caso

    Na ordenacao de n elementos ha *n!* possiveis resultados, que correspondem as permutacoes desses elementos. Portanto, **qualquer arvore binaria de comparacoes tera no minimo *n!* folhas**
        
    - Supondo que a altura dessa arvore seja `h`, entao `LB(n) = h` (LB -> lower boud).
        Sabemos que a quantidade de folhas de uma arvore binario de altura h e <=2^h^, portanto n! <= 2^h^.
        Ou serja, h >= log~2~ n!
            
        Conclui-se que **LB(n) >= log~2~ n!**

    n! pode ser grande de mais, nestes casos pode ser calculado usando **aproximacao de Stirling**:
    $$ n! \approx \sqrt{2 \pi n} (\frac{n}{e})^{n} \Longrightarrow  \log_{2} n! \approx O(1) + O(\log_{2} n) + O(n \log_{2}n) - O(n) \Longrightarrow LB(n) = \Omega (n \log_{2} n)$$

    Desta forma, se econtrarmos um algoritimo que resolva ordenacao em tempo $O(n \log_{2} n)$, ele sera **otimo** e esse problema estara **computacionalmente resolvido**.

   

### Intercalacao
- Problema:
    Dado um vetor inteiro de tamanho n, bipartidos em dois subvetores, ambos ordenados. Fazer um procedimento que retorne o vetor intercalado tambem ordenado.
    
```c
    void intercala(int *v, int e, int m, int d)
    {
        int *temp, i, fim_esq = m-1;
        temp = (int *) malloc(d * sizeof(int));

        for (i=0; e <= fim_esq && m < d; i++)
        {
            if (v[e] < v[m])
            {
                temp[i] = v[e];
                e++;
            } else {
                temp[i] = v[m];
                m++;
            }
        }

        for (; e <= fim_esq; e++, i++)
        {
            temp[i] = v[e];
        }

        for (; m < d; m++, i++)
        {
            temp[i] = v[m];
        }

        for (i = 0; i < d; i++)
        {
            v[i] = temp[i];
        }

        free(temp);
    }
```

### Merge Sort
- Segue a tecnica de divisao e conquista. Intuitivamente opera da seguinte forma:
    - Divisao: Quebra a sequencia de n elementos a serem ordenados em duas subsequencias de n/2 cada.
    - Conquista: Classifica-se ambas subsequencias recursivamente, utilizando ordenacao por intercalacao.
    - Combinacao: Intercala-se ambas subsequencias para formar a solucao do problema original

- Pros e Contras:
     - Pros: ligeiramente melhor que outros algoritimos.
     - Contras: Requer no minimo o dobro de memoria em comparacao a outros algoritimos.

$O(n \log_{2} n)$
```c
    void mergeSort(int *v, int e, int d)
    {
        int meio;
        if (e < d)
        {
            meio = (d + e)/2;
            mergeSort(v, e, meio);
            mergeSort(v, meio+1, d);
            intercala(v, e, meio+1, d);
        }
    }
```

## Particionamento

### Problema do Particionamento
Dado um vetor `v` de `n` posicoes e um indice `p` qualquer, desenvolva um procedimento que garanta que todos os elementos com **indice menores que `p` sao menores ou iguais a `v[p]`** e todos os elementos com indices **maiores que `p` sao maiores que `v[p]`**

$$ V[0] ... V[p-1] \leq V[p] \lt V[p+1] ... V[n-1] $$

### Particionamento
```
pm = -1
enquanto i < n-1
    v[i] <= v[p] ?
        sim:
            pm = pm + 1
            troca v[i] com v[pm]
            i = i + 1
        Nao:
            i = i + 1
```
p e o pivo, considerado como o `v[n-1]` (ultimo elemento), pm -> primeiro menor
Consumo de Tempo: $O(n)$
```c
    int particiona( int *v, int n)
    {
        int pm = -1, i, aux;
        for (i=0; i < n-1; i++)
        {
            if (v[i] <= v[n-1])
            {
                pm++;
                aux = v[pm];
                v[pm] = v[i];
                v[i] = aux;
            }
        }

        aux = v[pm+1];
        v[pm+1] = v[n-1];
        v[n-1] = aux;
        return pm+1;
    }
```

obs: com a realizacao do particionamento, **o pivo fica na posicao correta do vetor ordenado**. Aplicando esse algoritmo recursivamente, implementa-se o quicksort

### Quick Sort
Considerado o metodo de ordenacao mais eficiente ate os dias atuais.`

- **Particiona**
```c
    int particiona(int *v, int e, int d)
    {
        int pm = e-1, i, aux;
        for (i = e; i < d; i++)
        {
            if (v[i] <= v[d])
            {
                pm++;
                aux = v[pm];
                v[pm] = v[i];
                v[i] = aux;
            }
        }

        aux = v[pm+1];
        v[pm +1] = v[d];
        v[d] = aux;
        return pm+1;
    }
```
- **Quick Sort**
```c
    void quickSort(int *v, int e, int d)
    {
        int p;
        if (e < d)
        {
            p = particiona(v, e, d);
            quickSort(v, e, p-1);
            quickSort(v, p+1, d)
        }
    }
```
Melhor Caso: $O(n * log_{2}n)$
Pior Caso: $O(n^2)$

- **Caso Medio**
    $O(n * log_{2}n)$ no caso medio, com numero de comparacoes sendo 39% maior que no melhor caso, ou seja, no caso medio a eficiencia e mais proxima do melhor caso do que do 

### Quick Sort Aleatorio
Ideia: fugir do pior caso, sempre

- **Quick Sort**
```c
    void quickSort(int *v, int e, int d)
    {
        int p, tam, i, aux;
        if (e < d)
        {
            //trocar o pivo com um elemento aleatorio no meio do vetor
            tam = (d-e)+1;
            i = (rand()%tam)+e;
            aux = v[d];
            v[d] = v[i];
            v[i] = aux;

            p = particiona(v, e, d);
            quickSort(v, e, p-1);
            quickSort(v, p+1, d)
        }
    }
```

## Resumo de Eficiencia
- **Bubble Sort**
    - Pior Caso: $O(n^2)$
    - Melhor Caso: $O(n^2)$
    (complexidade de espaco constante)
- **Selection Sort**
    - Pior Caso: $O(n^2)$
    - Melhor Caso: $O(n^2)$
    (complexidade de espaco constante)
- **Insertion Sort**
    - Pior Caso: $O(n^2)$
    - Melhor Caso: $O(n)$
    (complexidade de espaco constante)
- **Merge Sort**
    - Pior Caso: $O(n * log_{2}n)$
    - Melhor Caso: $O(n * log_{2}n)$
    (complexidade de espaco de $n$)
- **Quick Sort**
    - Pior Caso: $O(n^2)$
    - Melhor Caso: $O(n * log_{2}n)$


---

# Heap

Heap e uma arvore *binaria* com duas propriedades:
- **Balanceamento**: E uma arvore completa (completa == ter todos os filhos), com a eventual excecao do ultimo nivel, onde as folhas sempre estao nas posicoes mais a esquerda
- **Estrutural**
    - Heap de **Maximo**: O valor armazenado em cada no *nao e menor* que os de seus filhos. (o valor do no sempre e maior ou igual aos seus filhos).
    - Heap de **Minimo**: O valor de cada no *nao e maior* que os de seus filhos. (o valor do no sempre e menor ou igual aos seus filhos).

## Relacoes de Heap representado em vetor

Um heap e representado em um vetor de forma que cada no da arvore possui um indice, partindo do 0 - no raiz, 1-filho da esquerda, 2-filho da direita, 3-Filho da esquerda de 1, 4-Filho da direita de 1...

- A raiz esta em v[0]. **O maior elemento da colecao sempre estara no indice 0 do vetor**. (heap max).
- o *Filho Esquerdo* de um no `i` esta sempre no indicie `2i+1`
- *Pai* de um no `i` esta sempre no indice `(i-1)/2` (arrendondado pra baixo)
- **Ultimo Pai** (ultimo no que tem filhos) sempre esta no indicie `(n/2) - 1` com a divisao arredondada para baixo
    - Consequencia: **Folhas**: Qualquer no com indice `i`, `(n/2) <= i < n` trata-se de no da folha

## Perda da Propriedade Estrutural

Caso um no de um heap perca a sua propriedade estrutural, podera recupera-la trocando de valor com o seu filho maior. Isso pode ser feito atraves do algoritmo **Peneirar (Sift)**

Uma vez que o filho trocou de lugar com o pai, a subarvore que protagonizou a troca pode ter perdido a propriedade estrutural do heap e tambem precisara invocar SIFT para ela.

## Construcao de um Heap

O algoritmo CONSTRUIR transforma um vetor qualquer em um heap.

Como os indicies `i`, `(n/2)` <= `i` < `n` sao folhas, basta aplicar *peneirar* entre as posicoes 0 e `(n/2)-1`, ou seja, todos os nos que sao pais.

## Operacoes Basicas de um Heap
- **Operacoes Principais**
    - Incluir item no Heap.
        deve ser a folha no ultimo nivel, na primeira posicao disponivel mais a esquerda. Se estiver cheio, comece mais um nivel. Chame `construir`
    - Remover Item do Heap (remover maximo)
        Troca-se o elemento raiz, indice 0, com o ultimo elemento do heap. Decrementa-se a quantidade. Invoca-se `peneirar` na raiz.

- **Opeacoes Secundarias** (apoiam as Ops Principais)
    - Filho Esquerda
    - Filho Direita
    - Pai
    - Ultimo Pai
    - Peneirar
    - Construir (obtem heap a partir de um vetor qualquer)

## Heap Sort - Ordenacao de heaps binarios

Pros: Mais estavel que QuickSort
Contras: COnstruir o heap consome muita memoria
Consumo de tempo no pior caso: $O(n * log_{2}n)$

- **Funcionamento**
    1. Transformacao de um vetor em um heap binario (constroiHeap)
    1. Ordenacao
        1. A cada iteracao obtem-se o maior elemento do heap (raiz do heap, indice 0 do vetor) e adicione-o em um segmento ordenado
        1. Apos a subtracao da raiz, reorganiza-se o heap (restauraHeap - ou - peneirar)

