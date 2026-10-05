#include <stdio.h>
#include <stdlib.h>

int compara (int a, int b){
	if(a < b) return b;
	else return a;
}
int main(){
	
	int valores[10];
	int maior, menor;
	
	printf("vamos ler os valores: \n");

	for (int i = 0; i < 10; i++){
		scanf("%d",&valores[i]);
	}

    for (int i = 9; i >= 0; i--){
		printf("%d \n",valores[i]);
	}
		
	return 0;
}
