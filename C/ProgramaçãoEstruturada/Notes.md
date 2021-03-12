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

