# Notas de Aula

## 1 Estrutura de Dados
Manipulacao de dados Compostos
- **Exemplo**
    ```c
    struct ponto
    {
        float x;
        float y;
    }

    int main(void)
    {
        struct ponto p;
        printf("Digite as coordenadas do ponto (x,y)\n");
        scanf("%f %f", &p.x, &p.y);
        printf("Coordenadas dadas: (%.2f, %.2f)\n", p.x, p.y);

        return 0;
    }

    ```

- **Ponteiros para Estruturas**
    - Acesso ao *valor* de um campo ```x``` de uma variavel *estrutura* ```p```: ```p.x```
    - Acesso ao *valor* de um campo ```x``` de uma variavel *ponteiro* ```p```: ```p->x```
    - Acesso ao *endereco* de um campo ```x``` de uma variavel *ponteiro* ```p```: ```p.x```

- **Definicao de Tipos**
    ```c
    typedef unsigned char Uchar;
    typedef struct ponto Ponto;
    ```

    ```c
    #definindo tipos em um comando so
    typedef struct ponto
    {
        float x;
        float y;
    } Ponto;
    ```
- **Tipo Enum**
    ```c
    enum bool
    {
        TRUE = 1,
        FALSE = 0
    };
    typedef enum bool Bool;
    ```

## 2 Tipo Abstrato de Dados
Exemplo: ```TAD Ponto```

- **Modulo**: um arquivo com funcoes que representam apenas parte da implementacao de um projeto
- **Arquivo objeto**: resultado de compilar um modulo (```.o``` ou ```.obj``` )
- **Ligador**: junta todos os arquivos objeto em um unico executavel

- **Exemplo de compilacao**:
    ```>gcc -c str.c -o str.o```
    ```>gcc -c prog1.c -o prog1.o```
    ```>gcc -o prog1.exe str.o prog1.o``` 

- **Tipo Abstrato de Dados - TAD**:
    Um TAD define:
    - um novo tipo de dado
    - o conjunto de operacoes para esse tipo
    Para um TAD, eh necessario conhecer sua funcionalidade, nao sua implementacao

    Para construir um TAD, eh necessario:
    - arquivo ```ponto.h``` -> define tipos e o **prototipo** das funcoes
    - arquivo ```ponto.c``` -> implementacoes de fato

## 3 Fila

- FILA -> First In First Out
- Pilha -> Last In, First Out

## 4 Cadeia de Caracteres

- Vetor do tipo `char` terminado por ``` '\0' ```
```c
    // equivalentes
    char cidade[] = "Rio";
    char cidade[] = {'R', 'i', 'o', '\0'};
```

- **Leitura via `scanf`:**
    - Especificador de formato `%c`:
        - Nao pula carcteres brancos (espaco`' '`, tabulacao `'\t'`, ou nova linha `'\n'`)
        ```c
            char a;
            scanf(" %c", %a); /* o branco no formato pula brancos da entrada */
        ```
    
    - Especificador de formato `%s`:
        Le uma cadeia de caracteres **nao brancos** (pula eventuais caracteres brancos antes da cadeia)

        ```c
            char cidade[81];
            scanf("%s", cidade);
        ```
        Se o usuario digitar `Rio de Janeiro`, apenas `Rio` sera capturado
    
    - Especificador de formato `%[...]`:
        `%[...]` lista todos os caracteres permitidos
        `%[^...]` lista todos os caracteres nao permitidos

        `%[aeiou]` - leitura prossegue ate encontrar caractere que nao seja vogal
        `%[^aeiou]` - leitura prossegue ate encontrar caractere que seja vogal
        `%[^\n]` - le sequencia de caracteres ate que haja uma quebra de linha (Ent)

- **Biblioteca `string.h`**

| desc        | funcao 
| ----------- | ------
| comprimento | strlen 
| copia       | strcpy
| concatena   | strcat
| compara     | strcmp

- **Constante cadeia de caracteres**
    ```c
    char s1[] = "Rio de Janeiro";
    ```
    - `s1` eh um vetor de char, inicializado com a cadeia `Rio de Janeiro`, seguida do caractere nulo
    - `s1` ocupa 15 bytes de memoria
    - eh valido escrever `s1[0] = 'X'` pois `s1`  eh um vetor
    - 

- **Constante cadeia de caracteres**
    ```c
    char* s2 = "Rio de Janeiro";
    ```
    - `s2` eh um **ponteiro** para char, inicializado com o endereco de memoria da area onde a constante `Rio de Janeiro` esta armazenada
    - `s2` ocupa 4 bytes de memoria
    - **nao eh valido** escrever `s2[0] = 'X'` pois nao eh possivel alterar um valor constante

- **Vetor de cadeias**
  - Alocacao estatica: matriz
  - Alocacao dinamica: vetor de ponteiros (cada cadeia eh alocada dinamicamente)

### Parametros de Funcao main

```c
int main(int argc, char** argv)
{
    ...
}
```
- argc:
    recebe o numero de argumentos passados para o programa
- argv:
    vetor de cadeia de caracteres que armazena os nomes passados como argumento

## 5 Arvores

Um conjunto de nos tal que:
    - Existe um no r, denominado **raiz**, com zero ou mais sub-arvores cujas raizes estao ligadas a r
    - Os nos raizes destas sub-arvores sao os **filhos** de r
    - As **folhas** ou **nos externos** sao nos sem filhos

- Propriedade fundamental de arvores: **so existe um caminho da raiz para qualquer no**

- **Altura de uma arvore**: comprimento do caminho mais longo da raiz ate uma das folhas
    - Altura de uma arvore vazia eh `-1`
- **Nivel de um no**: a raiz esta no `nivel 0`
    - O ultimo nivel da arvore eh a altura da arvore
- Arvore cheia: n_nos = 2^(h+1) - 1
- **Arvore Degenerada**: todos os nos internos tem uma unica sub-arvore associada

### Arvore Binaria
Cada no contem zero, um ou dois filhos

## 6 Hash Table

Necessita de mais memoria, proporcional ao numero de elementos armazenados

- **Funcao de dispersao**
    - Mapeaia uma chave de busca a um indice na tabela
    - Colisao: duas ou mais chaves apontando para o mesmo indice
    - Deve ser eficientemente avaliada e e as chaves devem ser bem espalhadas

- **Dimensao da Tabela**
    - Deve ser escolhida para diminuir o numero de colisoes
    - Costuma ser um valor primo
    - **Taxa de Ocupacao**
        - Deve ser inferior a 75%
        - 50% tras bons resultados
        - 25% ou menos representa gasto excessivo de memoria

- **Tratamento de Colisao -> Estrategia**
    - Uso da primeira posicao consecutiva livre
        - tende a concentrar os lugares ocupados na tabela
    - Uso de uma segunda funcao de dispersao
        - evita a concentracao de posicoes
    - Uso de listas encadeadas
        - Cada elemento da tabela hash representa um ponteiro para uma lista encadeada

## Heap (binario)

Arvore binaria completa
- *Min* heap: cada no eh *menor* que seus filhos
- *Max* heap: cada no eh *maior* que seus filhos

- **Insert**
    - Insira o elemento no final do heap e o faca subir ate a posicao correta
    - Compare com o elemento pai:
        - Se estiver em ordem, terminou
        - Se nao estiver, troque com o pai e repira ate terminar ou chegar na raiz

- **Remove**
    - Retira-se sempre a raiz
    - Coloque na raiz o ultimo elemento do heap e faca-o descer ate a posicao correta
    - Troque com o maior filho ate estar em ordem ou chegar na folha

## Otimizacao Combinatoria - Introducao

Se as variaveis sao continuas, o problema eh de otimizacao continua. Se as variaveis sao discretas, o problema eh conhecido como otimizacao combinatoria

- **Definicao**
    - Uma instancia de um problema de otimizacao eh um par(F,c) onde F eh um conjunto cujos elementos sao chamados de solucoes viaveis e c:F->R uma funcao de custo
    - O Problema eh encontrar um f* em F para o qual c(f*) <= c(y) para todo y em F
    - f* eh solucao otima

    - **Um problema de otimizacao eh um conjunto de instancias**
        - Uma *instancia* contem o conjunto de dados de entrada que fornecem uma solucao
