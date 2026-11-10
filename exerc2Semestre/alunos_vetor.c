#include <stdio.h>
#include <stdlib.h>

int main() {
    int vet_notas[10];
    int i, num;

    printf("Cadastre as notas dos alunos:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &vet_notas[i]);
    }

    system("cls");

    printf("Qual nota deseja ver (numero do aluno): ");
    scanf("%d", &num);

    if (num > 0 && num <= 10) {
        printf("Nota do aluno %d: %d\n", num, vet_notas[num - 1]);
    } else {
        printf("Nota nao cadastrada!\n");
    }

    return 0;
}
