# Listas

Uma lista e uma estrutura de dados em que os elementos estao organizados em uma ordem linear.
Uma lista pode ser:

1. **Simplesmente Ligada**: A partir de um elemento, nao se alcanca o elemento anterior
1. **Duplamente Ligada**: A partir de um elemento, se alcanca o anterior
1. **Ordenada**: A ordem linear da lista corresponde a ordem das chaves
1. **Nao Ordenada**: Qualquer ordem
1. **Circular**: A partir do primeiro elemento da lista se alcanca o Ultimo. E a partir do ultimo se alcanca o primeiro
1. **Nao Circular**: A partir do primeiro elemento nao se alcanca o ultimo. E do ultimo nao se alcanca o primeiro

Uma lista pode ser implementada de forma
1. **Estatica**: os elementos sao armazenados em um vetor
1. **Dinamicas**: Os elementos sao alocados dinamicamente conforme necessidade. Cada elemento armazena os dados e um ponteiro para o proximo elemento da lista

- **Estrutura de Dados do tipo Lista**:
    - Lista Estatica Sequencial (LES)
    - Lista Estatica Encadeada (LEE)
    - Lista Dinamica Encadeada (LDE)
    - Lista Dinamica Duplcamente Encadeada (LDDE)

## Lista Estatica Sequencial

Seja `L` uma lista com `n` elementos e `i` um indicie da lista tal que `0 <= i <= n-1`

- **Caracteristicas de uma lista L do tipo LES**:
    1. Os elementos da lista estao ordenados atraves de um campo chave
    1. Sao armazenados fisicamente em posicoes consecutivas
    1. A insercao de um elemento na posicao `L[i]` causa o deslocamento para a direita de `L[i]` ao ultimo elemento
    1. A eliminacao do elemento `L[i]` requer o deslocamento a esquerda do elemento `L[i+1]` ao ultimo

- **Operacoes Basicas**:
    1. Insrcao e um elemento
    1. Eliminacao de um elemento
    1. Consulta da pertinencia de um elemento



