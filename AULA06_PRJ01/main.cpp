#include <iostream>


// Função para imprimir o array
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


void separaPivo(int vetor[], int maximoVetor, int elementosVetor, int pivo,
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

void quicksortIterativo(int array[],int maxTamanho, int tamanho) {
    // Vetores auxiliares para dividir e juntar
    int *vetorParte1 = (int *)malloc(tamanho * sizeof(int));
    int *vetorParte2 = (int *)malloc(tamanho * sizeof(int));
    // Escolhe o pivô no meio da sublista
    int pivo = array[tamanho / 2];
    // Divide a lista em duas partes
    int tamParte1, tamParte2;
    separaPivo(array,maxTamanho, tamanho, pivo,
               vetorParte1,  &tamParte1,
	   	       vetorParte2,  &tamParte2);
	if(tamParte1 > 1){
		quicksortIterativo(vetorParte1,maxTamanho,tamParte1);
	}
	if(tamParte2 > 1){
		quicksortIterativo(vetorParte2,maxTamanho,tamParte2);
	}
    // Junta as duas partes novamente na lista original
    juntaListas(array,vetorParte1, vetorParte2, tamParte1, tamParte2,pivo)      
    free(vetorParte1);
    free(vetorParte2);
}




int main(int argc, char** argv) {
	int lista[100];
	int tamanhoMax = 100;
	int nrElementos = 7; 
	lista[0]= 8; lista[1]=3;  lista[2]= 1; lista[3]=7;
	lista[4]= 0; lista[5]=10; lista[6]=2;
	printf("Lista original:\n");
    imprimirArray(lista, nrElementos);
	
	quicksortIterativo(lista,tamanhoMax,nrElementos);

    printf("Lista ordenado:\n");
    imprimirArray(lista, nrElementos);
	
	
	return 0;
}