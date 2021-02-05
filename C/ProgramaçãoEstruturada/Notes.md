# Anotações das aulas

## Semana 01

leitura de vars:

```c
scanf("%d", &a)
```

Obs de alocação de memória:
    Ao se alocar uma var ```int var``` , há a necessidade de ser inicialiar (ex, ```var = 0```) ou em tempo de execução será utilizado o valor para aquela var aponta

- **Linguagens Compiladas x Interpretadas**

    - **Compilada**
        Código-fonte traduzido diretamente para _machine code_, como C
    - **Interpretada**
        Código-fonte traduzido para _machine code_ apenas no momento da execução, como Java ou Python

- **Compilação**
    - Código Fonte => **Compilador** => Programa objeto.
        ...O Programa Objeto é então executado. (é compilado para o OS específico)


    - Código Fonte C => **Compilador** => Programa Objeto => **Linkeditor** => Programa Objeto Completo
        É possível compilar um programa em C separadamente, e depois juntar com o linkeditor. (usado bastante em libs).

- **Entrada e Saída**
    Em C, são utilizadas funções para as operações de entradas e saídas.
    Funções básicas ficam  na biblioteca padrão, stdio.
    Para incluir: ``` #include <stdio.h> ```

    - Declaração na saída / entrada (```printf() scanf() ```):
        %d => int
        %ld => long int
        %lld => long long int
        %f => float
        %lf => long float
        %c => char
        %s String (char vector)
        %p => ponteiro
    
    - ```scanf("%d", &num)``` => recebe **endereços de memória** como argumento
        > O scanf recebe os endereços de memória das variáveis. O "&" serve para obter o endereço de memória da variável.

    - ```printf()``` => recebe **valores** como argumento.

- **Tamanhos dos Dados**
    ```sizeof()``` => retorna quantos *bytes* ocupa, tipo de retorno: ```long int```

- **Conversão de Tipo**
    ```c
    float num;
    num = 5 / 2; // returns 2
    num = 5 / 2.0; // returns 2.5
    num = 5 / ((float) 2); // also returns 2.5
    ```

- **Estruturas de Repetição**
    - while
    ```c
    while (<condition>)
    {
        ...
    }
    ```

    - do-while
    ```c
    do
    {
        ...
    } while (<condition>)
    ```

    - for
    ```c
    for (<initialize>; <condition>; <step>)
    {
        ...
    }
    ```