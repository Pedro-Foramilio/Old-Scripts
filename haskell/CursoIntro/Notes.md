# Cálculo λ
    Cálculo λ descreve computação apenas usando funções

- *Computabilidade* => estuda a possibilidade de resolver um problema seguindo um algoritimo

- Uma linguagem deve ser escrita em função se sintaxe e semantica

- **Sintaxe do Cálculo λ**
    - Composto de 3 elementos: Variáveis, definiçao e aplicaçao de funções
        ex: Função identidade: λx.x
    - **Sintaxe Haskell**
        troca ```λ``` por ```\``` e ```.``` por ```->```
    
    - Exemplo de Expressão em Cálculo λ:
        ```Haskell
        e :: x
            \x -> e
            e1 e2
        ```

        Um programa é definido por uma expressão ```e``` e pode assumir 3 formas:
            - Variável
            - Abstração
                ```\x -> e```, x é o parametro formal, e é o corpo da função
                Para qualquer valor de x, compute e
            - Aplicação
                ```e1 e2``` aplique o argumento e2 na função e1

        - Função com mais de um argumento:
            ```haskell
                \x -> (\y -> y) -- recebe dois args e retorna o seguindo
                \x -> (\y -> x) -- receve dois args e retorna o primeiro
                \x y -> y --recebe x e y e retorna ys
            ```

- **Boleanos**
    ```Verdadeiro``` = ```\x y -> x```
    ```Falso``` = ```\x y -> y```
    ```IF``` = ```\b x y -> b x y```
    se meu if (b) recebe x e y, então se x devolve x, senão devolve y
    ```NOT``` = ```\b -> IF b Falso Verdadeiro```
    ```AND``` = ```\b1 b2 -> IF b1 b2 falso```
    ```OR``` = ```\b1 b2 -> IF b1 verdadeiro b2```




