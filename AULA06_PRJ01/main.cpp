#include <iostream>
int main(int argc, char** argv) {
	int tamanho = 10;
	// Declarar o vetor de 20 inteiros
	int preco[tamanho];	
	// Percorrer cada elemento do vetor
	
	for(int p=0 ; p < tamanho  ; p++ ){	
	    // Atribuir 66 a cada elemento do vetor	
		preco[p]=0;		
	}	

	int p = 0;
	int resposta = 1;
	int precoLido;
	while(resposta ==1){
		printf("Digite o preco do item %i \n",p+1);
		scanf("%i",&precoLido);
		preco[p]= precoLido;
		printf("Voce quer continuar ? 1=Sim 2=Não \n");
		scanf("%i",&resposta);
		p++;		
	}
	
	for(int i=0 ; i < p ; i++){
		printf("Posicao %i do vetor preco = %i\n", 
		       i, preco[i]);
	}
	
	
	
	
	return 0;
}