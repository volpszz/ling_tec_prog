Funções (sub-programas): trecho de código reaproveitável, que pode ser chamado
quantas vezes for preciso. Serve para executar repetidamente uma tarefa
específica para a qual foi criada. // princípio da responsabilidade única

Sintaxe
tipo_retorno nome_da_funcao (lista de parametros) {   // para o tipo *void* o return é opcional
                                                       // parâmetros seguem o formato (tipo nome, ...)
    comando_1;
    comando_2;
    comando_3;
    return valor_compativel_com_o_tipo;
}
--------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
int contadorGlobal;

int somar(int x, int y) {
    return x + y;
}

int main(int argc, char *argv[]) {
    int resultadoMain;
    int m, n;

    if (m > n) {
        int troca;
        troca = m;
        m = n;
        n = troca;
    }

    int c, d;
    m = 10;
    n = 5;
    c = 1;
    d = 1;

    printf("%d", m);

    return 0;
}
