#include <stdio.h>

int main(){

    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
    char letra;

    printf("Insira uma letra: ");
    scanf(" %c", &letra);

    if (letra == vogais[0] || letra == vogais[3]) {
        printf("Aoba! \n");
    }
    else if (letra == vogais[2] || letra == vogais[4]) {
        printf("La ele \n"); 
    }
    else if (letra >= 'a' && letra <= 'w') {
        printf("67\n");
    }

    switch (letra){
        case 'y':
        printf("EITCHAN JOAOOO!!!! KIT COPO");
        break;

        case 'x':
        printf("EITCHAN COMO ELE TEM FORCA");
        break;

        case 'z':
        printf("GASTOU 150 REAIS E ELE VAI ESTOURAR UM BALAO EBAAA");
        break;
    }
    return 0;
}
