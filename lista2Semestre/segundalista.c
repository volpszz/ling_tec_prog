// Exercício 1
#include <stdio.h>

#define TAM_1 100

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int valores[TAM_1];
    int idx = 0;

    // Leitura dos 100 números usando laço while
    while (idx < TAM_1) {
        printf("\nDigite o número %d: ", idx + 1);
        scanf("%d", &valores[idx]);
        idx++;
    }

    // Exibição na ordem inversa de leitura
    printf("\nOrdem inversa:\n");
    for (idx = TAM_1 - 1; idx >= 0; idx--) {
        printf("\nNumero %d: %d", idx + 1, valores[idx]);
    }

    // Ordenação decrescente (Bubble Sort)
    for (int passo = 0; passo < TAM_1 - 1; passo++) {
        for (int pos = 0; pos < TAM_1 - 1 - passo; pos++) {
            if (valores[pos] < valores[pos + 1]) {
                trocar(&valores[pos], &valores[pos + 1]);
            }
        }
    }

    // Exibição em ordem decrescente
    printf("\n\nOrdem decrescente:\n");
    for (idx = 0; idx < TAM_1; idx++) {
        printf("\n %d", valores[idx]);
    }

    printf("\n");
    return 0;
}


// Exercício 2
#include <stdio.h>
#include <math.h>

int main() {
    double valor, mantissa;
    int exp = 0;

    printf("Digite um valor: ");
    scanf("%lf", &valor);

    mantissa = valor;

    if (mantissa != 0.0) {
        for (; mantissa >= 10.0; exp++) {
            mantissa /= 10.0;
        }
        for (; mantissa < 1.0; exp--) {
            mantissa *= 10.0;
        }
    }

    printf("Resultado: %.2lf x 10^%d\n", mantissa, exp);

    return 0;
}


// Exercício 3
#include <stdio.h>

void exibirBinario(int numero) {
    if (numero <= 0) {
        return;
    }
    exibirBinario(numero / 2);
    printf("%d", numero % 2);
}

int main() {
    int valor;

    scanf("%d", &valor);
    exibirBinario(valor);
    printf("\n");

    return 0;
}


// Exercício 4
#include <stdio.h>
#include <stdlib.h>

int obterMaior(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int numeros[10];
    int maximo;

    for (int cont = 0; cont < 10; cont++) {
        scanf("%d", &numeros[cont]);
        if (cont == 0) {
            maximo = numeros[0];
        } else {
            maximo = obterMaior(maximo, numeros[cont]);
        }
    }

    printf("%d e o maior\n", maximo);

    return 0;
}


// Exercício 5
#include <stdio.h>

int verificarPrimo(int num) {
    if (num < 2) {
        return 0;
    }
    for (int div = 2; div * div <= num; div++) {
        if (num % div == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int lista[100];
    int k = 0;

    while (k < 100) {
        scanf("%d", &lista[k]);
        k++;
    }

    for (k = 0; k < 100; k++) {
        printf("%d eh %s\n", lista[k], (lista[k] % 2 == 0) ? "par" : "impar");

        if (verificarPrimo(lista[k])) {
            printf("%d eh primo\n", lista[k]);
        } else {
            printf("%d nao eh primo\n", lista[k]);
        }
    }

    return 0;
}


// Exercício 6
#include <stdio.h>
#include <math.h>

double calcularDistancia(double ax, double ay, double bx, double by) {
    return hypot(bx - ax, by - ay);
}

int main() {
    double px1[10], py1[10], px2[10], py2[10];

    for (int idx = 0; idx < 10; idx++) scanf("%lf", &px1[idx]);
    for (int idx = 0; idx < 10; idx++) scanf("%lf", &py1[idx]);
    for (int idx = 0; idx < 10; idx++) scanf("%lf", &px2[idx]);
    for (int idx = 0; idx < 10; idx++) scanf("%lf", &py2[idx]);

    for (int idx = 0; idx < 10; idx++) {
        double dist = calcularDistancia(px1[idx], py1[idx], px2[idx], py2[idx]);
        printf("%.2lf\n", dist);
    }

    return 0;
}


// Exercício 7
#include <stdio.h>

int main() {
    int vetor[100];
    int pos = 0;

    while (pos < 100) {
        scanf("%d", &vetor[pos]);
        pos++;
    }

    for (pos = 0; pos < 99; pos++) {
        if (vetor[pos + 1] - vetor[pos] == 1) {
            printf("%d %d\n", vetor[pos], vetor[pos + 1]);
        }
    }

    return 0;
}