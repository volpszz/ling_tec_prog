#include <stdio.h>
#include <stdlib.h>

int main() {

    char cpf[12];
    int soma = 0;
    int resto;
    int primeiroDigito;
    int segundoDigito;

    printf("Escreva um numero de cpf: ");
    scanf("%11s", cpf);

    // primeiro digito
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }

    resto = (soma * 10) % 11;

    if (resto == 10) {
        resto = 0;
    }

    primeiroDigito = resto;

    
    soma = 0;

    // segundo digito
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }   

    resto = (soma * 10) % 11;

    if (resto == 10) {
        resto = 0;
    }

    segundoDigito = resto;

    // verifica se o cpf e valido
    if (primeiroDigito == (cpf[9] - '0') &&
        segundoDigito == (cpf[10] - '0')) {

        printf("CPF Valido!\n");

    } else {

        printf("CPF Invalido!\n");
    }

    return 0;
}