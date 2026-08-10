#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float base,altura,area;
	
	printf("Insira a base do triangulo: \n");
	scanf("%f",&base);
	printf("Insira a altura do triangulo: \n");
	scanf("%f",&altura);
	area = base * altura / 2.0;
	printf("A area do triangulo e: %.2f \n",area);
	return 0;
}
