# Anotações das aulas

## Semana 01 - Introdução

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
---

## Semana 02 - Funções e Vetores

- **Vetor | Basics**

    obs manhazinha:
    vetor ocupa ``` qtd_elementos * sizeof(<tipo>)```

    - Declarar Vetor:
    ```c
    //<tipo> <nome>[tamanho];

    //exemplos


    int idades[10];
    double vetor2[5];
    int valores[3] = {10, 20, 30};
    ```
    
    - Avessar valores em um vetor:
    ```c
    int vetor[5];
    vetor[4]; //acessa elemento 4 (i=0 to n)
    ```

    - Ler elementos em um vetor

    ```c
    int idade[10];
    int i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &idade[i]);
    }
    ```

- **Funções**
    Estrutura basica:
    ```
        tipoRetorno nomeFuncao(<listaParametros>){ ... }
    ```  

    - **PASSAGEM DE PARÂMETROS**
        Todo parâmetro é passado por **VALOR**.  
        Para passar um argumento por *referência* é preciso passar o valor do **ENDEREÇO DE MEMÓRIA (PONTEIRO)**.  

    - Procedimentos
        Um procedimento é uma função que *Não retorna valor*  
        Usamos ```void``` para indicar isto  
        Exemplo:
        ```c
            void mostraQuadrado(int num) {
                printf("%d\n", num * num);
                //observe que não há return
            }
        ``` 
    - Ordem declarativa
        Funções devem ser declaradas antes de serem chamadas (therefore, antes da main).
        ```c
            int calculaQuadrado(int n) {
                ...
            }

            int main() {
                ...
                calculaQuadrado(4);
                ...
            }
            
        ```
        EXCEPT se os "protótipos" forem declarados antes, então pode-se definir em whatever ordem.
        ```c
            int calculaQuadrado(int num);

            int main() {
                ...
                calculaQuadrado(3);
                ...
            }

            int calculaQuadrado(int n) {
                ...
            }


        ```
    - Escopo das Variáveis
        Escopo global: devem ser declaradas fora da main.    

    - **Vetores como argumento**

        Vetores como argumentos de funções são *pass by reference*.  
        O identificador de um vetor representa o endereço do primeiro elemento.  
        ```printf("%p\n", vetor)``` retornará o mesmo valor que ```printf("%p\n", &vetor[0])```. Por esta razão, funcao(vetor) passa um vetor *by ref*

        ```c
        void muda_valor(int vetor[]) {
            vetor[0] = 90;
        }

        int main() {
            int v[3] = {200, 500, 300};
            printf("%d %d %d\n", v[0], v[1], v[2]); //200 500 300
            nuda_valor(v);
            printf("%d %d %d\n", v[0], v[1], v[2]); //90 500 300
            
            return 0;
        }
        ```
    
---

## Semana 03 - Strings e Matrizes

- **Strings**
    Vetor de char: ``` char nome[n] = <string> ```  
    Impressão: ```printf("%s\n", string)```  
    String Prof. Paulo: [ P ][ r ][ o ][ f ][ . ][ ][ P ][ a ][ u ][ l ][ o ][ \0 ]  
    - Carcter final '\0'
        ```c
        char string[6];
        string[0] = 'U';
        string[1] = 'F';
        string[2] = 'A';
        string[3] = 'B';
        string[4] = 'C';
        string[5] = '\0'
        ```
    
    - Leitura de Strings
        ```scanf("%s", universidade)```
        Repare na ausência do &, isso porque ao usar o identificador do vetor sem os colchetes, ele representa o *endereço do primeiro elemento*  
        ```printf("%p\n", universidade)``` imprime o mesmo que ```printf("%p\n", &universidade[0])```  
        
    - gets: lê uma string
    - puts: imprime uma string e quebra a linha.

    ```c
    char texto[20];
    gets(texto);
    puts(texto);
    ```
    - *fgets*: limimta a quantidade de caracteres lida:
    ```c
    char frase[6]; //o sexto carctere sempre é o final da string \0, entao a frase tem na real 5 caracteres
    fgets(frase, 6, stdin); //stdin indica que a função é do teclado
    puts(frase);
    ```
    - scanf vs fgets:
        scanf para de ler uma string ao encotrar espaço, fgets não.
    
- **Matrizes**
    - Declarar Matriz ```<tipo> <nome>[tam1][tam2];```

    - Passagem de Matriz como parâmetro
        Necessário especificar ao menos a segunda dimensão.  
        ```void funcao(int nColunas, double m[][nColunas])```  
        ```void funcao(int nLinhas, nColunas, double m[nLinhas][nColunas])```

---

## Semana 04 - Recursão  

Muitos problemas podem ser resolvidos **combinando soluções de instancias menores** desses mesmos problemas.

- Recursão vai ocorrer por meio da definição de funções
    ```c
    int fatorial(n) {
        if (n == 0) //caso base
            return 1;
        else
            return n * fatorial(n-1);
    }
    ```
- Uma função recursiva deve possuir duas partes básicas
    - **Caso Base**
    - **Chamada Recursiva**: pelo menos uma chamada a si mesma
    Chamadas recursivas devem reduzir a instância em direção ao case base. 

- **Iteração x Recursão**
    Toda função pode ser escrita usando recursão (sem o uso de iteração). A recíproca é verdadeira.
    - *Exemplo: some primeiros n^k (1^k + 2^k + ... + n^k)
    ```c
    #include <math.h> //gcc -lm para linkar

    int iterativa(int k, int n) {
        int soma = 0;
        int i;
        for (i = 1; i <= n; i++) {
            soma += lround(pow(i, k));
        }
        return soma;
    }

    int recursiva(int k, int n) {
        if (n == 1)
            return 1;
        else
            return lround(pow(n, k)) + recursiva(k, n-1);
    }

    ```

- **Exemplos Adicionais**
    -*Fibonacci*
    ```c
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n-1) + fib(n-2);
    }
    ```
    -*Somar elementos de um vetor*
    ```c
    double iterativo(double v[], int n) {
        double soma = 0.0;
        int i;
        for (int i = 0; i < n; i++) {
            soma += v[i];
        }
        return soma;
    }

    double recursivo(double v[], int n) {
        if (n == 0) return 0.0;

        return v[n-1] recursiva(vetor, n-1);
    }
    ```
    -*Verificar se X está em um vetor*
    ```c
    int encontraX(int v[],int n, int numero) {
        if (n == 0) return 0;
        if (v[n-1] == numero) return 1;
        return encontrarX(v[], n-1, numero);
    }

    ```
    -*Menor elemento do vetor*
    ```c
    int menorElemento(int v[], int n) {
        if (n == 1) return v[0];
        
        int menor = menorElemento(v, n-1);
        int atual = v[n-1];
        return (atual < menor ? atual : menor);
    }

    ```
---

# Semana 05 - Ponteiros | Parte 1

- **Conceitos de Memória**
    Estrutura de um programa carregado em memória:
        Instruções | Dados Globais e Estáticos | *heap*--><--*Pilha*  
  
    - Instruções: código binário do programa
    - Dados: variáveis globais e estáticas (existem durante toda a execução do programa)
    - **Heap**: variáveis criadas por alocação dinâmica
    - **Pilha**: variáveis locais criadas para a execução de uma função
                  (são removidas após o término de uma função)
    
    - **Comando *size***
        Comando de terminal que mostra o tamanho que ocupada um programa.  
        *size programa.exe*  
        - text: Código
        - data: Área com dados inicializados
        - bss: Dados**globais** que não foram inicializados (são inicializados como zero)
        - dec e hex: soma dos valores acima (ou em dec, ou em hex)
    - **Memória**
    Podemos entender a memória como um vetor de bytes devidamente endereçados.  
    | 0x1051 | 0x1052 | 0x1053 | 0x1054 | 0x1055 | 0x1056 | 0x1057 |
    
    char temp = 2;
    &temp -> 0x1051 (que dentro, contem 00000010)
    int soma = 6;
    &soma -> 0x1055 que contem 00000000 00000000 00000000 00000110

- **Ponteiros**

    - Variável que armazena *endereço de memória*: ```char *ponteiro1; int *ponteiro2; ```
    Ponteiro1 aponta pra uma variável tipo char. Ponteiro2 é ponteiro para inteiro.
    ```c
    int n = 507;
    int *ptr; //declara um ponteiro de uma variável do tipo int
    ptr = &n; //faz o ponteiro ptr guardar o endereço de memória de n;
    //ptr APONTA para o endereço de memória de n, mas ele tem seu próprio endereço de memória individual.
    ```
    - __Como acessar o valor de VAR a partir do endereço de memória (*VAR)__
    ```c
    int n = 507; //declaraçao de var int
    int *ptr = &n; //declaração de ponteiro apontando para endereço de n
    *ptr = *ptr + 1; //altera valor da VARIAVEL que ptr aponta;

    printf("%d\n", n); // 508
    printf("%d\n", *ptr); // 508
    ```

- **Pass By Reference**

    - Para pasar parâmetros por refência é necessário passar **ponteiros** por valor

    ```c
    void mudaValor_a(double param) {
        param = 99;
        printf("A=%lf\n", param);
    }

    void mudaValor_b(double *param) {
        *param = 99;
        printf("B=%lf\n", *param);
    }

    int main() {

        double n = 507;
        printf("%lf\n", n); // 507.000000
        mudaValor_a(n); // A=99.000000
        printf("%lf\n", n);// 507.000000
        mudaValor_b(&n);// 99.000000
        printf("%lf\n", n);// 99.000000

        return 0;
    }
    ```
    - Se já possuímos um endereço de memória, podemos passar diretamente (sem &):
    ```c
    int num;
    int *pt1 = &num;

    scanf("%d", pt1); //lembrando que scanf recebe um endereço de memória
    ```
    - "Retornando" mais de um valor (procedimentos):  
    Usa-se Parâmentros por referência:
    ```c
    void divide(int dividendo, int divisor. int *quociente, int *resto) {
        *quociente = dividendo / divisor;
        *resto = dividendo % divisor;
    }
    ```
- **Alocação Dinâmica**

    - Necessário o uso de __```#include <stdlib.h>```__

    - **Alocar memória**: ```malloc```
        ```void* malloc( size_t size);``` passa o quanto de memória alocar
    - **Liberar memória**:
        ```void free(void* ptr);```
        **SEMPRE que se fazer uso de malloc DEVE-SE LIBERA-LA**  
        **free(n)**
    - Exemplo:
        ```c
        int *n; //declaração de ponteiro
        n = malloc(sizeof(int)); // alocação de memória
        //podemos usar um cast:
        // n = (int *) malloc(sizeof(int));
        ...
        free(n); //liberação de memória
        ```
    - Não há garantia que a memória seja alocada  
        Em caso de erro, é retornado o ponteiro NULL (internamente o valor zero)
    
    - **Valgrind**
        Ferramenta de análise que pode detectar vazamentos de memória, acessos indevios, etc
        ```c
        int *n;
        n = malloc(sizof(int));

        if (n != NULL) {
            *n = 507;
            printf("%d\n", n);
            free(n);
        } else {
            printf("Erro na alocação");
        }

        ```
        Na linha de comando:
        ```valgrind exemplo.exe```
        Se o ```free(n)``` for removido, será retornado infos de leak e heap
    
    - **Função** ```calloc```
        ```void* valloc(size_t nitems, size_t size)```
        - malloc: apenas aloca um bloco de memória (mas inicializa a memória)
        - calloc aloca e inicializa o bloco com zeros

    - Exemplo final:
        - Erro:
            ```c
            int *ptr_numero;// valor do ponteiro está indefinido
            scanf("%d", ptr_numero);
            printf("%d\n", ptr_numero);// faltou acessar o valor do inteiro apontado
            ```
        - Correto:
            ```c
            int *ptr_numero = malloc(sizeof(int));
            scanf("%d", ptr_numero);
            printf("%d\n", *ptr_numero);
            free(ptr_numero);
            ```

---

# Semana 06 - Ponteiros | Parte 2

- Alocação Dinâmica
```c
int *n;
n = malloc(sizeof(int));
free(n);
```

- **Alocação Dinâmica | Vetores**
    ```c
    int *n;
    n = malloc(5 * sizeof(int)); //Alocação de uma sequência de 5 inteiros
    free(n);
    ```
    
    - Preenchimento de vetor:
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int n;
        scanf("%d", &n);

        int *vetor = malloc(sizeof(int) * 5);

        int i;
        for (i = n-1; i >= 0; i--) {
            vetor[i] = n-i;
        }
        ...
        free(vetor);
    }
    ```
    - Não há garantia que memória seja alocada:
    ```c
    if(vetor == NULL) { //Em caso de erro, é retornado um ponteiro NULL
        printf("ERRO NA ALOCACAO\n");
        return -1;
    }
    ```

- **Aritimética de Ponteiros**

O efeito das operações aritiméticas sobre os ponteiros depende de como foram declarados:
    - int = 4 bytes | ptr + 1 incrementa 4 bytes
    - char = 1 byte | ptr + 1 incrementa 1 byte
    - double = 8 bytes | ptr + 1 incrementa 8 bytes

```c
char *ptr = malloc(sizeof(char)); // tem tamanho de 1 byte
printf("%p\n", ptr); // 0x556f17723010
ptr++;
printf("%p\n", ptr); // 0x556f17723011
// foi somado 1 byte

int *ptr = malloc(sizeof(int)); // tem tamanho de 4 byte
printf("%p\n", ptr); // 0x55c5f3c91010
ptr++;
printf("%p\n", ptr); // 0x55c5f3c91014
//foi somado 4 byte
```

- **Aritimética de ponteiros em vetores**  

    ```c
    int *vetor = malloc(sizeof(int) * 10);
    ```  
    Acessando valores:       
    - *(vetor + 0) = 80  <------> vetor[0] = 80
    - *(vetor + 4) = 507 <------> vetor[4] = 507
    obs: parenteses importante para a aritimética ser realizada antes de dereferenciar com *

- **Vetores como parâmetro e como retorno de função**

    Sabemos que vetores são passados por referência:
    ```c
    /*Ambas funções possuem mesmo comportamento*/

    void muda_valor(int vetor[]) {...}
    void muda_valor(int *vetor)  {...}

    /*Dentro das funções, é possivel fazer o seguinte: */
    ...{
        *vetor = 90;          //muda primeiro valor do vetor
        *(vetor + 1) = 507;  //muda segundo valor do vetor
    }
    ```

    - **Qual melhor forma de retornar um vetor ?**
        É necessário retornar seu ponteiro, mas NÃO RETORNE VARIÁVEL LOCAL
        ```c
        int* cria_vetor(int n) { //sinaliza que retorna um ponteiro
            int vetor[n];
            int i;
            for (i=0; i < n; i++) {
                vetor[i] = i+1;
            }

            return vetor; 
            //==> retorna um ponteiro para var LOCAL (falha de segmentação)
        }
        ```
    - É necessário alocação dinâmica DENTRO da função:
        ```c
        int* cria_vetor(int n) { //sinaliza que retorna um ponteiro

            int *vetor = malloc(sizeof(int) * n); //alocação dinâmica de memória

            int i;
            for (i=0; i < n; i++) {
                vetor[i] = i+1;
            }

            return vetor;
        }

        /*exemplo de funcao main*/
        int main() {
            int *v = cria_vetor(5);

            for(int i = 0; i < 5; i++) 
                printf("%d ", v[i]); //1 2 3 4 5
            printf("\n");
            free(v) //LIBERA MEMÓRIA

            return 0;
        }
        ```

- **Buffer overflow**

    Quando usamos um vetor, temos que ter atenção aos limites dele
    Quando o seguinte código passa de i = 9, possui comportamento imprevisível:
    ```c
    double vetor[10]
    for (int i = 0; i <=10; i++)
        printf("%d", i);
    ```
    Em casos de armazenamento de variáveis, pode-se ultrapassar por muito a quantidade de memória alocada, podendo interferir com valores de outras variáveis alocadas, por exemplo.

---

# Semana 07 - Ponteiros | Parte 3

- **Ponteiro para Ponteiro**
    - Um ponteiro para ponteiro armazena um endereço de memória de um ponteiro
    ```c
    int **ptr_i2;
    double **ptr_d2;
    char **ptr_c2;
    ```
    - Exemplo:
    ```int **ptr2;``` ptr2 = &ptr1, ou seja, ptr2 -----aponta---> ```int *ptr1``` e ptr1 = &num, ou seja, ptr1 ----aponta----> ```int num;```

    - Exemplo prático:
    ```c
    double nota_p1;
    scanf("%lf", &nota_p1);
    printf("%.2lf\n", nota_p1);

    double *ptr_nota = &nota_p1;
    scanf("%lf", ptr_nota); //ptr_nota --> guarda endereço de memória de nota_p1
    print("%.2lf\n", nota_p1);

    double **ptrptr_nota = &ptr_nota;
    scanf("%lf", *ptrptr_nota);
    /* ptrptr_nota aponta para o ptr_nota. O "*" retorna o valor da variável que ele aponta,
    ou seja, o valor de ptr_nota*/
    print("%.2lf\n", nota_p1);
    ```
- **Passagem de ponteiro como argumento de função**
    ```c 
    void le_vetor(int *vetor, int n) {
        vetor = malloc(sizeof(int) * n);
        int i;
        for (i = 0; i < n; i++) {
            vetor[i] = i;
        }
    }
    ```
    O **ponteiro** é uma variável e é passado por **valor**. Portanto, le_vetor não altera o valor do ponteiro.

    - Podemos resolver utilizando o ponteiro duplo:
        Dessa forma o ponteiro duplo ```**vetor``` é passado por valor, mas aponta para o ponteiro ```*vetor``` que queremos alterar, que é passado por referencia.    
        ```c
        void le_vetor(int **vetor, int n) {
            *vetor = malloc(sizeof(int) * n);
            int i;
            for (i = 0; i < n; i++) {
                (*vetor)[i] = i;
            }
        }
        ```
    
- **Alocação Estática vs Dinâmica (Matrizes)**

    Matriz é um vetor de vetores
    Matriz = 
    [
    [1, 2, 3], 
    [4, 5, 6], 
    [7, 8, 9]
    ]
    - Cada vetor é identificado pelo seu ponteiro (endereço do primeiro elemento)
        Portanto, uma matriz pode ser representada por um vetor de ponteiros.
    [ ] ----> [1, 2, 3]
    [ ] ----> [4, 5, 6]
    [ ] ----> [7, 8, 9]

    ```c
    int *matriz[4];
    /*alternatimante*/
    int **matriz;
    matriz = malloc(sizeof(int *) * 4);
    /*-------------*/
    for (int i = 0; i  < 4; i++) {
        matriz[i] = malloc(suzeif(int) * 3);
    }
    ```
    int **matriz;
    [
    [int *] -->[int, int, int],
    [int *] -->[int, int, int],
    [int *] -->[int, int, int],
    [int *] -->[int, int, int],
    ]

    - Escreva um programa para alocar uma matriz dinamicamente e preencher alguns valores em todas as posições:
        ```c
        int main() {
            int linhas = 4;
            int colunas = 3;
            int **matriz = malloc(sizeof(int *) * linhas);
            for (int i = 0; i < linhas; i++) {
                matriz[i] = malloc(sizeof(int) * colunas);
            }

            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    matriz[i][j] = (i + 1)*(j + 1);
                }
            }
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    printf("%d ",matriz[i][j]);
                }
                printf("\n");
            }
        
            /* liberação de memória*/

            for (int i = 0; i < linhas; i++) {
                free(matriz[i]);
            }
            free(matriz);
           return 0;
        }
        ```
    - **Função que retorna Matriz**
        Para retornar uma matriz, basta retornar o ponteiro dela (no caso, um ponteiro para ponteiro)
        ```c
        int** retorna_matriz(int linhas, int colunas) {
            int **m;
            m = malloc(sizeof(int *) * linhas);

            int c = 0;
            int i, j;
            for (i = 0; i < linhas i++) {
                    m[i] = malloc(sizeof(int) * colunas);
                for (j = 0; j < colunas; j++) {
                    m[i][j] = c++;
                }
            }

            return m;
        }
        ```
        - Utilizando este mecanismo de alocação dinâmica, podemos ter tamanho diferentes:
        ```c
        int **m;
        m = malloc(sizeof(int *) * 3);
        m[0] = malloc(sizeof(int) * 2);
        m[1] = malloc(sizeof(int) * 5);
        m[2] = malloc(sizeof(int) * 3);
        ```
    - **Matriz como parâmetro de função**

        ```c
        void gera_matriz(int ***matriz, int linhas, int colunas){//ponteiro para ponteiro para ponteiro
            ...
            *matriz = m;
        }
        ```

- **Ponteiro para Função**
    
    Em C podemos ter ponteiros para funções:
    ```c
    void (*ptr_fun)();
    ptr_fun = funcao_a;

    void (*ptr_fun2)(int);
    ptr_func2 = &funcao_b;
    ```
    uso do & é opcional;


    - Exemplo:
        ```c
        double soma(double a, double b) {
            return a + b;
        } 
        double multiplicacao(double a, double b) {
            return a + b;
        }

        int main() {
            double (*funcao)(double, double);

            funcao = &soma;
            printf("%.2lf\n", funcao(5, 6)); // 11.00

            funcao = &multiplicacao;
            printf("%.2lf\n", funcao(5, 6)); // 30.00
        
            return 0;
        }
        ```
    
    - **Vetor de ponteiro de funcoes**

        ```c
        int operacao;
        scanf("%d", &operacao);
        switch (operacao) {
            case 0: a = soma(a, b); break;
            case 1: a = multiplicacao(a, b); break;
            case 2: a = divisao(a, b); break;
        }

        /* podemos substituir esse switch por */
        int operacao;
        scanf("%d", &operacao);
        double(*funcoes[])(double, double) = {&soma, &multiplicacao, &divisao};
        a = funcoes[operacao](a, b);
        ```

---

# Semana 08 - Estrutura e Arquivos

- **Estruturas (struct)**
    Com *struct*, definimos um novo tipo de dados  
    Esse tipo é uma estrutura que permite a combinação de itens de diferentes tipos de dados  
    - Definição de um Novo tipo de dado *struct aluno*
        ```c
        struct aluno {
            int ra;
            char nome[100];
            char curso[20];
        }; // <---- detalhe de ;
        ```
    - Declarando uma variavel do novo tipo:
        ```c
        struct aluno aluno1;
        struct aluno aluno2, aluno3;
        ```
    - Acessando membros da estrutura:
        ```c
        struct aluno a1;
        a1.ra = 123;
        
        struct aluno a2, a3;
        a2.ra = 100;
        a3.ra = 200;

        scanf("%d", &a2.ra);
        scanf("%s", a2.curso);
        ```

    - Outro exemplo de uso:
        ```c
        #include <stdio.h>
        /* criação da struct */
        
        struct aluno {
            int ra;
            char nome[100];
            char curso[20];
        };
        /* --- */
        /* criação da main */
        
        int main() {
            struct aluno p;

            scanf("%d", &p.ra);
            scanf("%s", p.nome);
            scanf("%s", p.curso);

            printf("RA = %d Nome = %s Curso = %s", p.ra, p.nome, p.curso);

            return 0;
        }        
        ```

    - **Podemos criar um novo nome para o tipo de dados:**
        ```c
            typedef struct aluno novo_nome;

            novo_nome aluno1;
            novo_nome aluno2, aluno3;
        ```
    - Outros exemplos
        ```c
        #iclude <stdio.h>
        #include <math.h>

        struct ponto {
            int x, y;
        }
        typedef struct ponto t_ponto;

        double distancia(t_ponto p1. t_ponto p2) {
            return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
        }

        int main(){
            t_ponto p1, p2;
            p1.x = 3;
            p1.y = 4;
            p2.x = 1;
            p2.y = 2;

            printf("%.2lf\n", distancia(p1, p2));

            return 0;
        }
        ```
        - Forma alternativa de inicialização: ``` t_ponto p1 = {3, 4}```

- **Alocação Dinâmica de Estruturas**

    Tendo a struct :
    ```c
    typedef struct aluno t_aluno;
    struct aluno {
        int ra;
        char *nome;
        double nota;
    };
    ```
    Podemos alocar:  
    ```c
    t_aluno *a1;
    a1 = malloc(sizeof(t_aluno));
    t_aluno *a2 = malloc(sizeof(t_aluno));
    ```
    - Acessando membros a partir de ponteiro, temos 2 alternativas:
        - Derreferenciar ponteiro e acesso com *ponto*:
            ```c
            t_aluno *a1 = malloc(sizeof(t_aluno));
            (*a1).ra = 123;
            ```
        - Utilizar o operador ```->```:
            ```c
            t_aluno *a1 = malloc(sizeof(t_aluno));
            a1->ra = 123;
            ```
    - Exemplo Pratico:
        ```c
        #include <stdio.h>
        #include <stdlib.h>

        typedef struct disciplina t_disciplina;
        struct disciplina {
            int cod;
            char *nome;
            int creditos;
        };

        int main() {
            t_disciplina *pe = malloc(sizeof(t_disciplina));
            pe->cod = 555;
            pe->nome = "Programação";
            pe->creditos = 4;

            printf("Cod = %d Nome = %s Creditos = %d\n", pe->cod, pe->nome, pe->creditos);

            free(pe);

            return 0;
        }
        ```

    - Uma estrutura pode referenciar a si mesma:
        ```c
        struct disciplina {
            int cod;
            char *nome;
            int creditos;

            struct disciplina *requisito;
            //se naa usar ponteiro, a declaração se torna recursiva...
        };
        ```
        - Exemplo:
            ```c
            struct disciplina {
                int cod;
                char *nome;
                int creditos;
                struct disciplina *requisito;
            };

            int main() {
                struct disciplina pe;
                pe.cod = 555;
                pe.nome = "Programacao";
                pe.creditos = 4;
                pe.requisito = malloc(sizeof(struct disciplina));
                
                pe.requisito->cod = 444;
                pe.requisito->nome = "Informacao";
                pe.requisito->creditos = 5;
                pe.requisito->requisito = NULL;

                free(pe.requisito);

                return 0;
            }
            ```

- **Arquivos**

    Para usar arquivos, necessário abrir  ```fopen``` e fechar ```fclose```
    - Abertura de Arquivos:
        fopen recebe o modo de abertura do arquivo:
        ```c
        FILE* fopen(const char *filename, const char *mode);
        ```
        - "r": Somente leitura
        - "w": Escrita. Primeiro zera o arquivo
        - "a": Escrita no final do arquivo
        - "r+": Leitura e escrita. Aponta para o início do arquivo
        - "w+": Leitura e escrita. Primeiro zera o arquivo
        - "a+": Leitura e escrita. Leitura a partir do início e escrita no final do arquivo

    - Para arquivos binários usamos os modos "rb" "wb" "ab" "rb+" "r+b" "w+b" "ab+" "a+b"

    - Fechar Arquivo:
        ```c
        int fcoles(FILE *fp);
        ```

    - **Estrutura Básica**
        ```c
        #include <stdio.h>

        int main() {
            FILE *arquivo = NULL;
            arquivo = fopen("teste.txt", "w");
            fclose(arquivo);

            return 0;
        }
        ```
    
    - **Escrita e Leitura**
        - ```fputc``` / ```fgetc```
        - ```fputs``` / ```fgets```
        - ```fprintf``` / ```fscanf```

        - Exemplo: Escrita
            ```c
            FILE *arquivo = NULL;
            arquivo = fopen("teste.txt", "w");

            fprintf(arquivo,"Inicio do Arquivo\n");
            int n = 507;
            fprintf(arquivo, "Valor de n = %d\n", n);

            fclose(arquivo);
            ```
        - Exemplo: leitura
            ```c
            FILE *arquivo = NULL;
            arquivo = fopen("abc.txt, "r");

            char texto[100];

            fscanf(arquivo, "%s", texto);// quando chega num espaço, a leitura é encerrada
                                        // cada fscanf le palavra por palavra
            printf("%s\n", texto); // "Incio"

            fclose(arquivo);
            ```
            ...

            ```c
            FILE *arquivo = NULL;
            arquivo = fopen("abc.txt, "r");

            char texto[100];

            fgets(texto, 100, arquivo);//fgets não para em um espaço
                                        // cada fgets pega uma linha do arquivo
            printf("%s\n", texto); // "Inicio do Arquivo"

            fclose(arquivo);
            ```
        
        - Exemplo: Leitura e Escrita:
            ```c
            FILE *arquivo = NULL;
            arquivo = fopen("teste.txt", "a+");

            char texto[100];
            fscanf(arquivo, "%s", texto);
            printf("%s", texto);

            //Texto não foi adicionao ao final do arquivo, mas no final da primeira linha
            fprintf(arquivo, "Ola Ola\n");

            fclose(arquivo);
            ```
            - **Não execute operações de escrita e leitura intercaladas sen abtes reposicionar o fluxo (*stream*)**
                Uma forma de lidar com esse problema é fechar e abrir o arquivo, assim não é necessário o uso do modo "a+"

            - Uma forma correta:
                ```c
                FILE *arquivo = NULL;
                arquivo = fopen("abc.txt", "r");

                char texto[100];
                fscanf(arquivo, "%s", texto);
                printf("%s", texto);

                fclose(arquivo);
                arquivo = fopen("abc.txt", "a");

                fprintf(arquivo, "Ola Ola\n");

                fclose(arquivo);
                ```

    - **fseek**:
        ```c
        FILE *arquivo = NULL;
        arquivo = fopen("abc.txt", "a+");

        char texto[100];
        fscanf(arquivo, "%s", texto);
        printf("%s", texto);

        fseek(arquivo, 0, SEEK_SET);// stream estará localizado no final do arquivo

        fprintf(arquivo, "Ola Ola\n");
        fclose(arquivo);
        ```

- **Arquivos Binários**
    Podemos ler e escrever arquvios binários
    Dessa forma, é possivel armazenar estruturas alocadas em memória em um arquivo

    Usaremos as funções ```fwrite``` e ```fread```
    
    ```c
    size_t fwrite (const void *ptr, size_t size, size_t count, FILE *stream);
    /*
    *ptr: ponteiro para a região de memória que será escrita no arquivo
    size: tamanho de cada elemento
    count: quantidade de elementos
    *stream: ponteiro para o arquivo aberto
    */
    size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
    /*
    *ptr: ponteiro para a região de memória JÁ ALOCADA que receberá os dados do arquivo
    size: tamanho de cada elemento
    count: quantidade de elementos
    *stream: ponteiro para arquivo aberto
    */
    ```

    - Exemplo:
        Vamos armazenar uma lista de discos voadores (código e velocidade)

        Veremos um programa para armazenar o vetor com essa estrutura em um arquivo

        Depois teremos um programa para ler o arquivo e mostrar a lista de discos voadores no terminal

        ```c
        #include <stdio.h>
        #include <stdlib.h>

        struct disco_voador {
            int cod;
            double velocidade;
        };

        int main() {
            //programa para escrever binário

            struct disco_voador discos[3] = { {2, 4.5}, {6, 40.2}, {300, 1750.25} };

            FILE *arq = fopen("discos.bin", "wb");

            fwrite(discos, sizeof(struct disco_voador), 3, arq);
            
            fclose(arq);

            return 0;
        }
        ```
        
        Programa para ler o .bin:

        ```c
        #include <stdio.h>
        #include <stdlib.h>

        struct disco_voador {
            int cod;
            double velocidade;
        };

        void print_discos(struct disco_voador discos[], n) {
            int i;
            for(i = 0; i < n; i++) {
                printf("-> [%d] [%.2lf]\n", discos[i].cod, discos[i].velocidade);
            }
        }

        int main() {
            //programa para ler o .bin
            
            struct disco_voador *discos = malloc(sizeof(struct disco_voador) * 3)/

            FILE *arq = fopen("discos.bin", "rb");
            fread(discos, sizeof(struct disco_voador), 3, arq);

            fclose(arq);

            print_discos(discos, 3);
            free(discos);

            return 0;
        }
        ```

- **Estrutura File:**
    - FILE é uma estrutura (trecho do stdio.h do MinGW)
    ```c
    /*
    Some believe that nobody in their right mind 
    should make use of the internals of this structure
    */
   typedef struct _iobuf
   {
       char* _ptr;
       int _cnt;
       char* _base;
       int _flag;
       int _file;
       int _charbuf;
       int _bufsiz;
       char* _tmpfname;
   } FILE;
   ```

---

# Semana 09 - Ordenação e Busca

**Ordenação:** processo de rearranjar uma sequencia de elementos de acordo com a **chave** de cada elemento.

- Dois tipos de ordenação:
    - Interna: todas as chaves estão na memória principal;
    - Externa: grande parte das chaves estão em memória externa;

- Algoritimos de ordenação podem ser divididos entre:
    - **Baseados em Comparação:** 
        Bubble sort, Selection sort, Insertion sort, Merge sort, Quick sort, Heap sort.
    - **Baseados em Distribuição**
        Count sort, Radix sort, Bucket sort.
    
- Algorítimos Estáveis: ordem relativa de elementos com chaves iguais é mantida
- Algorítimos Instáveis: ordem relativa de elementos com chaves iguais *não* é mantida

                  
- **Algorítimos de ORDENAÇÃO SIMPLES**

    - **Selection Sort - O(n²)**
        - Ideia Geral: encontrar menor elemento, trocar menor elemento com primeiro elemento do vetor. Repetir com o restante do vetor (subvetor)

        - Comparações:
            - Melhor Caso: n(n-1)/2, O(n²)
            - Pior Caso: n(n-1)/2, O(n²)

        - Implementação:
        ```c
        #include <stdio.h>

        void selection_sort(vetor, n){
            int i;
            for (i = 0; i < n-1; i++) {

                int indice_menor = i;
                int k;
                //encontra menor elemento no subvetor
                for (k = i+1; k < n; k++) {

                    //para ordem descrescente: v[k] > v[indice_maior]
                    if (v[k] < v[i])
                        indice_menor = k;

                }
                //swap se indice for diferente
                if (indice_menor != i){
                    int tmp = v[i];
                    v[i] = v[indice_menor];
                    v[indice_menor] = tmp;
                }

            }
            return;
        }

        void imprimir(int *v, int n) {
            int i;
            for (i = 0; i < n; i++) {
                printf("%d ", v[i]);
            }
            printf("\n");

            return;
        }

        int main() {
            int n = 6;
            int vetor = {6, 9, 40, 3, 5, 16};

            imprimir(vetor, n);
            selection_sort(vetor, n);
            imprimir(vetor, n);

            return 0;
        }
        ```

    - **Bubble Sort - O(n²)**

        - Ideia geral: Inicia no primeiro elemento e compara os elementos dois a dois. Caso k > k+1, troca. Repete n-1. O processo aplicado garante que o maior elemento estará na última posição e na segunda iteração o segundo maior elemento na penúltima posição...

        - Comparações:
            - Melhor Caso: n-1, O(n) com parada antecipada
            - Pior Caso: n(n-1)/2, O(n²)

        - Implementação:
        ```c
        #include <stdio.h>

        //otimização: se não houver trocas em uma iteração completa, já está ordenado
        void bubble_sort(int *v, int n) {
            int i, k;
            for (i = 0; i < n-1; i++) {

                int trocou = 0; //otimização

                for (k = 0; k < n-1-i; k++) {

                    //para ordem descrescente: v[k] < v[k=1]
                    if (v[k] > v[k+1]) {
                        int tmp = v[k];
                        v[k] = v[k+1];
                        v[k+1] = tmp;
                        trocou = 1; //otimização
                    }
                } 
                if (!trocou) break; //otimização
            }
            return;
        }

        void imprimir(int *v, int n) {
            int i;
            for (i = 0; i < n; i++) {
                printf("%d ", v[i]);
            }
            printf("\n");

            return;
        }

        int main() {
            int n = 6;
            int vetor = {6, 9, 40, 3, 5, 16};

            imprimir(vetor, n);
            bubble_sort(vetor, n);
            imprimir(vetor, n);

            return 0;
        }
        ```

    - **Insertion Sort - O(n²)**

        - Ideia geral: Inicia com o subvetor de um elemento (primeiro elemento), therefore já ordenado. Depois avalia o próximo elemento e o insere na posição correta no subvetor ordenado. Agora o subvetor tem dois elementos. Repita até completar.

        - Comparações:
            - Melhor Caso: n-1. O(n)
            - Pior Caso: n(n-1)/2, O(n²)

        - Implementação:
        ```c
        #include <stdio.h>

        void insertion_sort(int *v, int n) {
            int i, k;
            for (i = 1; i < n; i++) { //considera o i = 0 como já ordenado

                int item_atual = v[i]; //guarda elemento atual

                //encontra indice para inserção e desloca elementos para a direita
                int indice_para_inserir = i;
                //ordem crescente: item_atual > v[k]
                for (k = i-1; k >= 0 && intem_atual < v[k] ; k--) {
                    v[k+1] = v[k];
                    indice_para_inserir--;
                }

                v[indice_para_inserir] = item_atual;
            }
            
            return;
        }

        void imprimir(int *v, int n) {
            int i;
            for (i = 0; i < n; i++) {
                printf("%d ", v[i]);
            }
            printf("\n");

            return;
        }

        int main() {
            int n = 6;
            int vetor = {6, 9, 40, 3, 5, 16};

            imprimir(vetor, n);
            insertion_sort(vetor, n);
            imprimir(vetor, n);

            return 0;
        }
        ```

- **Resumo Selection, Bubble, insertion**
    ```c
    void selection_sort(vetor, n){
            int i;
            for (i = 0; i < n-1; i++) {

                int indice_menor = i;
                int k;
                //encontra menor elemento no subvetor
                for (k = i+1; k < n; k++) {

                    //para ordem descrescente: v[k] > v[indice_maior]
                    if (v[k] < v[indice_menor])
                        indice_menor = k;

                }
                //swap se indice for diferente
                if (indice_menor != i){
                    int tmp = v[i];
                    v[i] = v[indice_menor];
                    v[indice_menor] = tmp;
                }

            }
            return;
        }
    
    void bubble_sort(int *v, int n) {
            int i, k;
            for (i = 0; i < n-1; i++) {

                int trocou = 0; //otimização

                for (k = 0; k < n-1-i; k++) {

                    //para ordem descrescente: v[k] < v[k=1]
                    if (v[k] > v[k+1]) {
                        int tmp = v[k];
                        v[k] = v[k+1];
                        v[k+1] = tmp;
                        trocou = 1; //otimização
                    }
                } 
                if (!trocou) break; //otimização
            }
            return;
        }
    
    void insertion_sort(int *v, int n) {
            int i, k;
            for (i = 1; i < n; i++) { //considera o i = 0 como já ordenado

                int item_atual = v[i]; //guarda elemento atual

                //encontra indice para inserção e desloca elementos para a direita
                int indice_para_inserir = i;
                //ordem crescente: item_atual > v[k]
                for (k = i-1; k >= 0 && intem_atual < v[k] ; k--) {
                    v[k+1] = v[k];
                    indice_para_inserir--;
                }

                v[indice_para_inserir] = item_atual;
            }
            
            return;
        }
    ```

- **Busca**

    Dados um vetor **v** e um valor *x*, verificar se o elemento *x* está em **v**. Se estiver, retornaro índice *i* da posição de *x* em **v**. Caso contrário, retorne *-1*.

    - **Busca linear/sequencial - O(n)**
        Verifica-se todos os elementos de um vetor.

        - Número de comparações:
            - Melhor Caso: 1
            - Pior Caso: n;

        - Implementação:
        ```c
        int busca_linear(int *v, int n, int x) {
            int i;
            for (i = 0; i < n; i++)
                if (v[i] == x)
                    return i;
            return -1;
        }
        ```

    - **Busca Binária - O(log(n))**

        Algoritimo de busca mais eficiente, mas requer que o vetor esteja ordenador. Busca realizada dividindo vetor até finalizar.

        - Número de comparações:
            - Melhor Caso: 
            - Pior Caso: iteração k: n / 2^(k-1)
                após k iterações, sobrará 1 elemento: 1 = n / 2^(k-1) => **k = log_base2(n) + 1**
        
        - Implementação:
        ```c
        int busca_binaria(int *v, int n, int x) {
            int esq = 0, dir = n-1;
            
            while (esq <= dir) {

                int meio = (esq + dir)/2;
                if (v[meio] == x)
                    return meio;
                else if (v[meio] < x) //if true, x ta na direita
                    esq = meio + 1;
                else //x ta na esquerda
                    dir = meio - 1;
            }
            return -1;
        }
        ```

- **Constantes**

    Duas formas principais de declarar uma constante em C:
    - Pré processador ```define``` ou palavra-chave ```const```

    - **Pré Processador**
        ```c
        #define <IDENTIDICADOR> <valor>
        ```
        Exemplo:
        ```c
        #include <stdio.h>
        #define MAX_N 50

        int main() {
            char nome[MAX_N];
            fgets(nome, MAX_N, stdin);
            puts(nome);
            
            return 0;
        }
        ```
    - **Palavra chave const**
        ```c
        const <tipo> <IDENTIDICADOR> = <valor>;
        ```
        Exemplo:
        ```c
        #include <stdio.h>
        const int MAX_N = 50;

        int main() {
            char nome[MAX_N];
            fgets(nome, MAX_N, stdin);
            puts(nome);
            
            return 0;
        }
        ```

    - **Constantes com Ponteiros**
        Podemos tornar o ponteiro (ou a variável que ele aponta) constante.
        ```c
        /* declara um ponteiro para um inteiro constante. Ou seja, o VALOR DO PONTEIRO pode ser alterado,
        mas a VARIÁVEL QUE ELE APONTA não */
        const int *ptr;

        int v[3];
        ptr = v; // OK
        ptr[2] = 40; // NOT OK
        ```
        Este tipo de constante pode ser usada quando queremos passar um ponteiro como parâmetro a uma função, mas não queremos que ela altere o conteúdo:
        ```c
        void imprimir_vetor(const int *v, int n) {
            int i;
            for (i = 0; i < n; i++) {
                printf("%d ", v[i]);
            }
        }
        ```
        Para o valor do ponteiro ser constante, declaramos da seguinte forma:
        ```c
        /* declara um ponteiro constante para um inteiro. Ou seja,
         o VALOR DO PONTEIRO não pode ser alterado, mas A variavel
         QUE ELE APONTA pode. */
        int v[5];
        int * const ptr = v;

        int v2[3];
        ptr[2] = 507; // OK
        ptr = v2;// NOT OK
        ```
        Para declarar um ponteiro constante que aponta para uma variável constante:
        ```c
        int v[5];

        const int * const ptr = v;

        int v2[3];
        ptr[2] = 507; // NOT OK
        ptr = v2; // NOT OK
        ```
    
---

# Semana 10 - Listas Ligadas | Parte 1

- Lista: estrutura de dados que permite operações básicas: Busca; Inserção; Remoção

- **Lista com vetor/arranjo**:
    Itens dispostos em um arranjo sequencial: | dados | dados | dados | dados |

    - Busca: É possível acessar elementos diretamente com índice, o que permite busca *sequencial* ou *binária* (vetor ordenado)
    - Inserção e Remoção: Pode necessitar de deslocamentos

- **Listas ligadas/encadeadas**:
    Estrutura de dados que armazena os itens de forma **não consecutiva** na memória. Cada item possui uma referência para o próximo: |dados, prox--|-->|dados, prox--|-->|dados,prox--|-->null

    - Tipos:
        - Listas simplesmente ligadas (com e sem nó cabeça)
        - Listas duplamente ligadas (com e sem nó cabeça)
        - Listas circulares

    - Busca: Acessar um item (por índice) requer percorrer a lista desde o início.
    - Inserção e Remoção: Não requer deslocamentos. Basta alterar a referênciar anterior e posterior ao item inserido ou removido

    |                | Lista com Vetor                                             | Lista Ligada                                         |
    | :------------- | :---------------------------------------------------------: | :--------------------------------------------------- |
    |  Busca         | Permite acesso direto a um item(busca sequencial e binária) | Requer percorrer a lista para acessar um item        |
    | Inserção       | Necessita de deslocamentos                                  | Não requer deslocamentos                             |
    | Remoção        | Necessita de deslocamentos                                  | Não requer deslocamentos                             |
    | Uso de memória | Armazena apenas os itens                                    | Armazena ao menos uma referência junto com cada item |

- **Listas Ligadas | Implementação**
    - Definição de struct:
    ```c
    typedef struct LinkedNode LinkedNode;
    struct LinkedNode {
        int data;
        LinkedNode *next;
    };
    ```
    - Exemplo: alocar 3 nós na memória e formar uma LL definindo o valor do ponteiro next de cada nó e imprimir os 3 nós. Criar uma função que percorre uma lista de tamanho arbitrário.

        ```c
        #include <stdio.h>
        #include <stdlib.h>
        //utilizando struct definido por LinkedNode

        void imprimir(LinkedNode *inicio) {
            LinkedNode *atual = inicio;
            
            while(atual != NULL) {
                printf("%d ", atual->data);
                atual = atual->next;
            }
            printf("\n");

            return;
        }

        int main() {
        /* declarando e criando cada node com seus dados */
            LinkedNode item1;
            item1.data = 10;

            LinkedNode item2;
            item2.data = 20;

            LinkedNode item3;
            item3.data = 30;

        /* linkando cada node */
            item1.next = &item2;
            item2.next = &item3;
            item3.next = NULL;

            imprimir(&item1);

            return 0;
        }
        ```
        Utilizando Alocação Dinâmica:
        ```c
        #include <stdio.h>
        #include <stdlib.h>
        //utilizando struct definido por LinkedNode

        void imprimir(LinkedNode *inicio) {
            LinkedNode *atual = inicio;
            
            while(atual != NULL) {
                printf("%d ", atual->data);
                atual = atual->next;
            }
            printf("\n");

            return;
        }

        int main() {
        /* declarando e criando cada node com seus dados */
            LinkedNode *item1 = malloc(sizeof(LinkedNode));
            item1->data = 10;

            LinkedNode *item2 = malloc(sizeof(LinkedNode));
            item2->data = 20;

            LinkedNode *item3 = malloc(sizeof(LinkedNode));
            item3->data = 30;

        /* linkando cada node */
            item1->next = item2;
            item2->next = item3;
            item3->next = NULL;

            imprimir(item1);

        /* Liberando memoria */
            free(item1);
            free(item2);
            free(item3);

            return 0;
        }
        ```


- **Listas Ligadas | Operações**

    - Inserir no final
        ```c
        LinkedNode *inserir_final(LinkedNode *inicio, int valor) {
            LinkedNode *novo = malloc(sizeo(LinkedNode));
            if (novo == NULL) return inicio; //caso de erro na alocação
             
            novo->data = valor;
            novo->next = NULL;

            if (inicio == NULL) //lista vazia
                return novo;
            
            LinkedNode *anterior = NULL;
            LinkedNode *atual = inicio;
            while (atual!= NULL) {
                anterior = atual;
                atual = atual->next;
            }
            anterior->next = novo;
            return inicio; //inicio sempre é o mesmo

        }

        int main() {
            LinkedNode *inicio = NULL;
            inicio = inserir_final(inicio, 10);
            inicio = inserir_final(inicio, 20);
            inicio = inserir_final(inicio, 30);

            imprimir(inicio);

            //liberação em breve
        }

        ```
    - Inserir no final - Versão Recursiva
        ```c
        LinkedNode *inserir_final(LinkedNode *inicio, int valor) {
            if (inicio == NULL) {
                LinkedNode *novo = malloc(sizeof(LinkedNode));
                novo->data = valor;
                novo->next = NULL;
                return novo;
            }

            inicio->next = inserir_final(inicio->next, valor);
            return inicio;
        }

        int main() {
            LinkedNode *inicio = NULL;
            inicio = inserir_final(inicio, 10);
            inicio = inserir_final(inicio, 20);
            inicio = inserir_final(inicio, 30);

            imprimir(inicio);

            //liberação em breve
        }
        ```
    - Otimização de Inserção no Final:
        É possível sempre armazenar o ponteiro para o ultimo item da lista, não precisando percorrer a lista completa.
        
    - Remover
        ```c
        LinkedNode *remover(LinkedNode *inicio, int valor) {
            LinkedNode *anterior = NULL;
            LinkedNode *atual = inicio;

            //sai do while quando achou valor ou percoreu a lista toda (atual == null)
            while (atual != NULL && atual->data != valor) {
                anterior = atual;
                atual = atual->next;
            }

            if (atual != NULL) {
                //remoção não é o primeiro
                if (anterior != NULL) {
                anterior->next = atual->next;//pula atual
                } else {
                    inicio = atual->next; //case remover primeiro elemento
                }

                free(atual); //removendo da memória
            }
            return inicio;
        }
        ```
    - Remover - Versão Recursiva
        ```c
        LinkedNode *remover(LinkedNode *inicio, int valor) {
            if (inicio == NULL) return NULL;//lista nula
            if (inicio->data == valor) {//remove primeiro item
                LinkedNode *temp = inicio->next;
                free(inicio);
                return temp;
            }
            inicio->next = remover(inicio->next, valor);
            return inicio;
        }
        ```
- **Liberação de Lista Ligada**

    ```c
    void liberar_lista(LinkedNode *inicio) {
        LinkedNode *atual = inicio;
        LinkedNode *remover;
        while (atual != NULL) {
            remover = atual;
            atual = atual->next;
            free(remover);
        }
    }
    int main() {
        LinkedNode *inicio = NULL;
        inicio = inserir_final(inicio, 10);
        inicio = inserir_final(inicio, 20);
        inicio = inserir_final(inicio, 30);

        imprimir(inicio);

        liberar_lista(inicio);

        return 0;
        }
    ```
    - liberação recursiva
        ```c
        void liberar_lista(LinkedNode *inicio) {
            if (inicio == NULL) return;
            liberar_lista(inicio->next);
            free(inicio);            
        }
        ```

- Exercício Exemplo:

    - Escreva um programa que le numeros em uma lista ligada até que o usuário digite -1 e depois imprima a lista de números:
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct LinkedNode;
    struct LinkedNode {
        int data;
        LinkedNode *next;
    };

    LinkedNode *inserir_final(LinkedNode *inicio, int valor) {
        if (inicio == NULL) {
            LinkedNode *novo = malloc(sizeof(LinkedNode));
            if (novo == NULL) return inicio;
            novo->data = valor;
            novo->next = NULL;
            return novo;
        }

        inicio->next = inserir_final(inicio->next, valor);
        return inicio;
    }

    void imprimir(LinkedNode *inicio) {
        LinkedNode *atual = inicio;
        while (atual != null) {
            printf("%d ", atual->data);
            atual = atual->next;
        }
        printf("\n");

        return;
    }

    void liberar_lista(LinkedNode *inicio) {
        if (inicio == NULL) return;
        liberar_lista(inicio->next);
        free(inicio);

        return;
    }

    int main() {
        LinkedNode *inicio = NULL;
        int n;
        scanf("%d", &n);

        while (n != -1) {
            inicio = inserir_final(inicio, n);
            scanf("%d", &n);
        }

        imprimir(incio);
        liberar_lista(inicio);

        return 0;
    }

    ```



