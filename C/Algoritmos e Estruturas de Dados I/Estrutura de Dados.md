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

# Filas

- Uma Fila e uma estrutura de dados que admite insercao de novos elementos e remocao de elementos antigos
- Uma fila "queue" e uma estrutura sujeita a seguinte regra de operacao:
    **Sempre que houver uma remocao, o elemento removido e o que esta na estrutura a mais tempo**
- FIFO: *First In First Out*

- **Por que usar filas?**
    - Custo: Isercao e Remocao O(1) com busca O(n)

- **Formas de Implementacao**:
    1. **Estaticas**: os elementos sao armazenados em um vetor
    1. **Dinamicas**: Os elementos sao alocados dinamicamente conforme necessidade. Cada elemento armazena os dados e um ponteiro para o proximo elemento da lista.

- **Estrutura de Dados do tipo Fila**:
    1. Fila Estatica
    1. Fila Estatica Circular
    1. Fila Dupla (Deque)
    1. Fila Dinamica
    1. Fila Dinamica Circular
    1. Fila de Prioridade

## Fila Estatica

Seja `Q` uma fila com `n` elementos e `i` um indice da lista tal que `0 <= i <= n-1`

- **Operacoes Basicas**
    1. Insercao de um elemento na Fila (Enfileirar)
    1. Elimitar (Desenfileirar)

- **Problema de Overflow**
    Ao se utilizar uma Fila estatica como vetor de tamanho `n`, ao se inserir `n` elementos, por mais que se remova `n-1` elementos, o indicador de fim e comeco apontam para o fim da fila, havendo entao um problema de nao permitir inserao mesmo com a fila possuindo `1` elemento. alem disso, remover o ultimo elemento ira causar o indicador de inicio apontar para a posicao `n`, alem dos limites da lista.

    Um *fix* para este problema e detectar que a fila esta vazia e resetar o vetor, ou seja, indicar inicio e fim pro comeco do vetor como riginalmente comecaram. Isso no entando ainda nao permite que uma lista que foi preenchida ate o limite, apos `j < n` remocoes permita `j` insercoes. E necessario esvaziar por completo a fila para utiliza-la novamente.

    **Solucao Definitiva: Fila Circular**

## Fila Estatica Circular

- Os elementos da lista sao dispostos conforme sua entrada na fila
- So e permitido a inclusao no final da fila e eliminacao no inicio (FIFO)
- Quando se desenfilera um item, a posicao pode ser usada novamente para novos, resolvendo o problema da Fila Estatica
- **Apos o ultimo item do vetor vem o primeiro, e antes do primeiro tem o ultimo**

## Fila Dinamica

- Itens encadeados conforma entrada
- Se inclui itens na cauda (apos o ultimo)
- Eliminacao so permitida do inicio
- *FIFO? First In First Out*

- Em Ciencia da Computacao uma *fila dinamica* e uma estrutura de dados que:
    1. Consiste de uma sequencia de registros
    1. Cada registro tem um campo que contem um ponteiro para o proximo da fila

# Pilhas

- Admite insercao e remocao de itens em apenas uma das extremidades chamada topo.

- Sempre que houver insercao ou remocao de elemento, isso acontecera no topo.
    Ao remover, deixara a pilha o que estiver a **menos** tempo na pilha

- LIFO: *Last In First Out*

- **Por que usar filas?**
    - Custo: Isercao e Remocao O(1) com busca O(n)

- **Estrutura de dados do tipo Pilha**:
    1. Pilha Estatica
    1. Pilhas Multiplas
    1. Pilha Dinamica

## Pilha Estatica

- **Operacoes Basicas**
    1. Insercao de um elemento na Pilha
    1. Remocao de um elemento da Pilha

## Pilha Dinamica

- Os itens sao encadeados conforme entrada na pilha
- So se inclui itens no topo da pilha (LIFO)
- Nao sao armazenados fisicamente em posicoes contiguas de memoria.
    **Rastreabilidade promovida pelos ponteiros**
- *LIFO: Last In First Out*


- Em Ciencia da Computacao, uma *pilha dinamica* e uma estrutura de dados que:
    1. Consiste de uma sequencia de registros
    1.Cada registro tem um campos que contem um ponteiro para o anterior da pilha

