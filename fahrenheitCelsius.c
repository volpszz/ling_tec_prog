#include <stdio.h>
#include <stdlib.h>


int main(){
    double entradaTemperatura;
    char grandeza;

    printf("Digite uma temperatura: ");
    scanf("%lf",&entradaTemperatura);

    printf("Qual grandeza (C/F): ");
    scanf(" %c",&grandeza);


    if (grandeza == 'F'){
        entradaTemperatura = (entradaTemperatura - 32) * 5/9;
        printf("%.2lf",entradaTemperatura);
    }   
    if (grandeza == 'C'){
        entradaTemperatura = (entradaTemperatura * 9/5) + 32;

        printf("%.2lf",entradaTemperatura);
    }
    

}