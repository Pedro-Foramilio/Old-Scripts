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


