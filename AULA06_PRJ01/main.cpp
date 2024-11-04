#include <iostream>


// Função para imprimir o array
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

////////////////////////////////////////////////////////////////
//////////////////////// QUICK SORT ////////////////////////////
////////////////////////////////////////////////////////////////

/// QUICK SORT PARTE I
// Função para juntar duas listas em um vetor final
void juntaListas(int *vetor, int *lista1, int *lista2, int tam1, int tam2,int pivo) {
    int i;
    // Copia os elementos da lista1 para o vetor
    for (i = 0; i < tam1; i++) {
        vetor[i] = lista1[i];
    }
    // Adiciona o pivô na posição correta
    vetor[i++] = pivo;    
    // Copia os elementos da lista2 para o vetor
    for (int j = 0; j < tam2; j++) {
        vetor[i + j] = lista2[j];
    }
}

// Função para juntar duas listas em um vetor final
void juntaListas(int *vetor, int *lista1, int *lista2, int tam1, int tam2) {
    int i;
    // Copia os elementos da lista1 para o vetor
    for (i = 0; i < tam1; i++) {
        vetor[i] = lista1[i];
    }        
    // Copia os elementos da lista2 para o vetor
    for (int j = 0; j < tam2; j++) {
        vetor[i + j] = lista2[j];
    }
}

/// QUICK SORT PARTE II
void separaPivo(int vetor[], int elementosVetor, int pivo,
                int *vetorParte1, int *tamParte1, 
				int *vetorParte2, int *tamParte2) {
    *tamParte1 = 0;
    *tamParte2 = 0;
    // Percorre o vetor e separa os elementos
    for (int i = 0; i < elementosVetor; i++) {
        if (vetor[i] < pivo) {
            vetorParte1[(*tamParte1)++] = vetor[i];  // Adiciona na parte 1
        } 
		if  (vetor[i] > pivo) {
            vetorParte2[(*tamParte2)++] = vetor[i];  // Adiciona na parte 2
        }
    }
}

/// QUICK SORT PARTE III
void quicksortRecursivo(int array[], int tamanho) {
    // Vetores auxiliares para dividir e juntar
    int *vetorParte1 = (int *)malloc(tamanho * sizeof(int));
    int *vetorParte2 = (int *)malloc(tamanho * sizeof(int));
    // Escolhe o pivô no meio da sublista
    int pivo = array[tamanho / 2];
    // Divide a lista em duas partes
    int tamParte1, tamParte2;
    separaPivo(array,tamanho, pivo,
               vetorParte1,  &tamParte1,
	   	       vetorParte2,  &tamParte2);
	if(tamParte1 > 1){
		quicksortRecursivo(vetorParte1,tamParte1);
	}
	if(tamParte2 > 1){
		quicksortRecursivo(vetorParte2,tamParte2);
	}
    // Junta as duas partes novamente na lista original
    juntaListas(array,vetorParte1, vetorParte2, tamParte1, tamParte2,pivo);    
    free(vetorParte1);
    free(vetorParte2);
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
//////////////////////// MERGE SORT ////////////////////////////
////////////////////////////////////////////////////////////////
/// MERGE SORT PARTE I ////
// Função para intercalar duas listas em um vetor final
void intercalaListas(int *vetorFinal, int *lista1, int tam1, int *lista2, int tam2) {
    int indiceLista1 = 0, indiceLista2 = 0, indiceListaFinal = 0;
    // Intercala os elementos de lista1 e lista2 no vetorFinal
    while (indiceLista1 < tam1 && 
	       indiceLista2 < tam2) {
        if (lista1[indiceLista1] <= lista2[indiceLista2]) {
            vetorFinal[indiceListaFinal] = lista1[indiceLista1];
            indiceLista1++;
        } else {
            vetorFinal[indiceListaFinal] = lista2[indiceLista2];
            indiceLista2++;
        }
        indiceListaFinal++;
    }
    // Copia os elementos restantes de lista1, se houver
    while (indiceLista1 < tam1) {
        vetorFinal[indiceListaFinal] = lista1[indiceLista1];
        indiceLista1++;
        indiceListaFinal++;
    }
    // Copia os elementos restantes de lista2, se houver
    while (indiceLista2 < tam2) {
        vetorFinal[indiceListaFinal] = lista2[indiceLista2];
        indiceLista2++;
        indiceListaFinal++;
    }
}

/// MERGE SORT PARTE III ////
void mergeSortRecursivo(int listaPrincipal[],int tamanho) {
	// Caso base: se o array tem menos de 2 elementos, já está ordenado	
    if (tamanho < 2) {   // "Condição de "cauda" 	
        return; 
    }
    int posicaoMeio = tamanho / 2;
    int *Lista1 = listaPrincipal; // Pega a ponta esquerda
    int *Lista2 = listaPrincipal + posicaoMeio; // Pega a ponta do meio pra frente
    int tamanhoLista1 = posicaoMeio; // Já que ela começa em zero, a posição do meio 
	                                 // é o tamanho
    int tamanhoLista2 = tamanho - tamanhoLista1; // O total menos o tam. lista 1
    mergeSortRecursivo(Lista1, tamanhoLista1);
    mergeSortRecursivo(Lista2, tamanhoLista2);
    int aux[2*tamanho]; // Por segurança
    intercalaListas(aux, Lista1,tamanhoLista1, Lista2,tamanhoLista2);
    /// Joga de volta para a lista original
    for (int i = 0; i < tamanho; i++) {
        listaPrincipal[i] = aux[i];
    }	
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
	int lista[100];	
	int nrElementos = 7; 
	
	//// TESTE do QUICK SORT ////
	lista[0]= 8; lista[1]=3;  lista[2]= 1; lista[3]=7;
	lista[4]= 0; lista[5]=10; lista[6]=2;
	printf("Lista original:\n");
    imprimirArray(lista, nrElementos);		
	quicksortRecursivo(lista,nrElementos);
    printf("Lista ordenado com quickSort:\n");
    imprimirArray(lista, nrElementos);
		
	//// TESTE do MERGE SORT ////		
	lista[0]= 18; lista[1]=3;  lista[2]= 10; lista[3]=17;
	lista[4]= 0; lista[5]=50; lista[6]=2;
	printf("Lista original:\n");
    imprimirArray(lista, nrElementos);
	mergeSortRecursivo(lista,nrElementos);
    printf("Lista ordenada com MergeSORT:\n");
    imprimirArray(lista, nrElementos);
	
	return 0;
}