void insertionSort(int lista[], int tamanho) {
    for (int indiceAtual = 1; indiceAtual < tamanho; indiceAtual++) {
        int valorAtual = lista[indiceAtual];
        int posicaoComparacao = indiceAtual - 1;

        // Move elementos maiores que o valor atual para a direita
        while (posicaoComparacao >= 0 && lista[posicaoComparacao] > valorAtual) {
            lista[posicaoComparacao + 1] = lista[posicaoComparacao];
            posicaoComparacao--;
        }
        // Insere o valor atual na posição correta
        lista[posicaoComparacao + 1] = valorAtual;
    }
}