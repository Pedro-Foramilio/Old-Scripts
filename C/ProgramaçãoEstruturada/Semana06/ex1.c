/*
Faça um programa que leia um inteiro (que será o tamanho de um vetor de double a ser alocado), depois fique lendo números double:

• Cada número deverá ser inserido ordenado (ordem crescente) em um vetor. Assuma que sempre haverá espaço para inserir elementos (não serão fornecidos mais números do que a capacidade do vetor alocado).
• Após cada inserção, imprima o vetor completo, com uma casa decimal para cada número (apenas imprima os números lidos, desconsidere as posições do vetor que não foram preenchidas). Inclua uma quebra de linha ao final da impressão do vetor.
O programa encerra quando o usuário digitar o número -1 (não imprima o vetor após o usuário digitar -1, apenas encerre o programa).

Exemplo de funcionamento:
100 (tamanho do vetor de double a ser alocado)
Digite: 5
5.0
Digite: 8
5.0 8.0
Digite: 2
2.0 5.0 8.0
Digite: 7
2.0 5.0 7.0 8.0
Digite: -1
Importante: utilize malloc para alocar o vetor (não declare vetor com colchetes). Para acessar as posições no vetor, pode usar colchetes neste exercício. Não use variáveis globais.

Lembre-se de liberar toda memória alocada com malloc/calloc!
*/

