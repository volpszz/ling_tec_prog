#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[50];
    double nota1, nota2, nota3, media;

    printf("Qual seu nome: ");
    scanf(" %49[^\n]", nome);

    printf("Digite as tres notas: ");
    scanf("%lf %lf %lf", &nota1,&nota2,&nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("\nAluno: %s\n", nome);
    printf("Media: %.2lf\n", media);

    if (media >= 7.0 && media <= 10.0) {
        printf("Aprovado!\n");
    } else if (media >= 4.0 && media < 7.0) {
        printf("Exame!\n");
        printf("Faltam %.2lf pontos para 10.0\n", 10.0 - media);
    } else {
        printf("Reprovado!\n");
    }

    return 0;
}