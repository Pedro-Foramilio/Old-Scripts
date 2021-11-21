# Notas Haskell

- **Caracteristicas Principais**
    - Funções Puras
    - Recursão
    - Avaliação Preguisosa (avaliado apenas se e quando necessário)

- **Efeito Colateral e Estados**
    - Efeito Colateral é quando uma função altera algum estado global do sistema (ler dados, alterar valor de variáveis)

    - *Funções Puras* não apresentam efeito colateral

- Códigos Concisos e declarativos
    ```take 100 [x | x <- nat, primo x>]```
    Pegar 100 primeiros numeros de uma lista que são primos

- **Imutabilidade**
    ```Haskell
    x = 1.0
    x = 2.0
    --erro
    ```
    Como consequência, fazer laços é inviável... utilizamos recursão

    - Comparação:
        ```c
        int x = 1.0;
        for (int i = 1; i <= 10; i++) {
            x = x * 2;
        }
        printf("%d\n", x);
        ```
        ou
        ```Haskell
        f 0 = 1
        f n = 2 * f (n-1) --f(x) é o mesmo que f(x)
        print(f 10)
        ```
- **Funções de alta ordem**
    ```Haskell
    print (aplique dobro [1,2,3,4])
    >[2,4,6,8]
    ```

- **Tipos Polimorfos**
    permite definir funções genéricas que funcionam para classes de tipos. Por ex, a função ```fst``` retorna o primeiro elemento de uma tupla, os tipos não importam.
    ```Haskell
    fst :: (a,b) -> a
    fst (x,y) = x
    ```
- **Avaliação Preguiçosa**
    ```Haskell
    listaInf = [1..] --1, 2, 3...
    print (take 10 listaInf)
    ```

- **Funções**
    Nome da função seguido dos parâmetros:
    ```Haskell
    f a b -- f(a,b)
    f a b + c*d --f(a, b) + c*d
    ```

    ```Haskell
    f x = a*x + b
        where
            a = 1
            b = 3
    z = f 2 + 3
    ```

---