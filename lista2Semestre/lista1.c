
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ---------------EXERCICIO 1--------------------------------

void exercicio1() {

    int numeros[100];
    int aux;
    int i, j;

    for (i = 0; i < 100; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);
    }

    
    printf("\nOrdem inversa:\n");

    for (i = 99; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }

   
    for (i = 0; i < 99; i++) {
        for (j = 0; j < 99 - i; j++) {
            if (numeros[j] < numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }

    printf("\nNumeros do maior para o menor:\n");

    for (i = 0; i < 100; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");
}

// ---------------EXERCICIO 2--------------------------------

void exercicio2() {

    double numero, a;
    int n = 0;

    printf("Digite um numero positivo: ");
    scanf("%lf", &numero);

    if (numero <= 0) {
        printf("Digite um numero maior que zero.\n");
        return;
    }

    a = numero;

   
    while (a >= 10) {
        a = a / 10;
        n++;
    }

    while (a < 1) {
        a = a * 10;
        n--;
    }

    printf("Notacao cientifica: %.4f x 10^%d\n", a, n);
}

// ---------------EXERCICIO 3--------------------------------

void exercicio3() {

    int n, binario[64];
    int i = 0, j;

    printf("Digite um numero (maior que 0 e ate 64): ");
    scanf("%d", &n);

    if (n <= 0 || n > 64) {
        printf("Numero invalido!\n");
        return;
    }


    while (n > 0) {
        binario[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Numero em binario: ");

    for (j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }

    printf("\n");
}

// ---------------EXERCICIO 4--------------------------------

void exercicio4() {

    int numeros[10];
    int maior;
    int i;

  
    for (i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);
    }

    maior = numeros[0];

 
    for (i = 1; i < 10; i++) {
        maior = (maior + numeros[i] +
                 abs(maior - numeros[i])) / 2;
    }

    printf("%d eh o maior\n", maior);
}

// ---------------EXERCICIO 5--------------------------------

void exercicio5() {

    int numeros[100];
    int i, j;
    int primo;

 
    for (i = 0; i < 100; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < 100; i++) {

        printf("\nNumero: %d\n", numeros[i]);

        
        if (numeros[i] % 2 == 0) {
            printf("Par\n");
        } else {
            printf("Impar\n");
        }

       
        primo = 1;

        if (numeros[i] <= 1) {
            primo = 0;
        } else {
            for (j = 2; j <= numeros[i] / j; j++) {
                if (numeros[i] % j == 0) {
                    primo = 0;
                    break;
                }
            }
        }

        if (primo == 1) {
            printf("Primo\n");
        } else {
            printf("Nao primo\n");
        }
    }
}

// ---------------EXERCICIO 6--------------------------------

void exercicio6() {

    double x1[10], y1[10];
    double x2[10], y2[10];
    double distancia[10];
    int i;

   
    for (i = 0; i < 10; i++) {

        printf("\nCoordenadas %d\n", i + 1);

        printf("Digite x1: ");
        scanf("%lf", &x1[i]);

        printf("Digite y1: ");
        scanf("%lf", &y1[i]);

        printf("Digite x2: ");
        scanf("%lf", &x2[i]);

        printf("Digite y2: ");
        scanf("%lf", &y2[i]);
    }

    
    for (i = 0; i < 10; i++) {

        distancia[i] = sqrt(
            pow(x2[i] - x1[i], 2) +
            pow(y2[i] - y1[i], 2)
        );

        printf("\nDistancia %d: %.2f\n",
               i + 1, distancia[i]);
    }
}

// ---------------EXERCICIO 7--------------------------------

void exercicio7() {

    int numeros[100];
    int i;
    int encontrou = 0;

    
    for (i = 0; i < 100; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);
    }

    printf("\nNumeros consecutivos encontrados:\n");

    
    for (i = 0; i < 99; i++) {

        if ((long long)numeros[i + 1] - numeros[i] == 1 ||
            (long long)numeros[i] - numeros[i + 1] == 1) {

            printf("%d e %d\n",
                   numeros[i], numeros[i + 1]);

            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("Nenhum numero consecutivo encontrado.\n");
    }
}



int main() {

    printf("\n===== EXERCICIO 1 =====\n");
    exercicio1();

    printf("\n===== EXERCICIO 2 =====\n");
    exercicio2();

    printf("\n===== EXERCICIO 3 =====\n");
    exercicio3();

    printf("\n===== EXERCICIO 4 =====\n");
    exercicio4();

    printf("\n===== EXERCICIO 5 =====\n");
    exercicio5();

    printf("\n===== EXERCICIO 6 =====\n");
    exercicio6();

    printf("\n===== EXERCICIO 7 =====\n");
    exercicio7();

    return 0;
}
