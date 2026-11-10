#include <stdio.h>
#include <stdlib.h>


int main(){
    int vet_notas[10];
    int i,num;

    printf("Cadastre as notas dos alunos");
    for(i= 0; i<10; i++) scanf("%d", &vet_notas[i]);
    system("cls");

    printf("Qual nota deseja ver (num aluno): ");
    scanf("%d",&num);
    printf("%d",vet_notas[num]);
    return 0;

}
