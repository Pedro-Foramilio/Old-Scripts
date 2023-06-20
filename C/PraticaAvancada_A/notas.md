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



    
