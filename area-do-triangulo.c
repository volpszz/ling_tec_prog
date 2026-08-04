#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	float base,altura,area;
	
	base = 10;
	altura = 20;
	area = (base * altura) / 2;
	
	printf("area do triangulo de base (%.2f) e altura (%.2f) = %.2f",base,altura,area);
	
	return 0;
}
