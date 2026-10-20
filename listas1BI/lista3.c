#include <stdio.h>
#include <math.h>

#define GRAVIDADE 9.8f
#define ATRITO    0.5f
#define PI_APROX  3.14f

/* ---------- Funções auxiliares (INSS e IRPF) ---------- */

float descontoINSS(float bruto) {
    float aliquota;

    if (bruto <= 1412.00)        aliquota = 0.075f;
    else if (bruto <= 2666.68)   aliquota = 0.09f;
    else if (bruto <= 4000.03)   aliquota = 0.12f;
    else                         aliquota = 0.14f;

    return bruto * aliquota;
}

float descontoIRPF(float base) {
    float aliquota, deducao;

    if (base <= 2259.20) {
        return 0.0f;
    }
    else if (base <= 2826.65) { aliquota = 0.075f; deducao = 169.44f; }
    else if (base <= 3751.05) { aliquota = 0.15f;  deducao = 381.44f; }
    else if (base <= 4664.68) { aliquota = 0.225f; deducao = 662.77f; }
    else                      { aliquota = 0.275f; deducao = 896.00f; }

    return base * aliquota - deducao;
}

/* ---------- Exercício 1: CPF ---------- */

int calcularDigito(const int *d, int n) {
    int soma = 0;
    int peso = n + 1;

    for (int i = 0; i < n; i++) {
        soma += d[i] * peso;
        peso--;
    }

    int resto = (soma * 10) % 11;
    return (resto == 10) ? 0 : resto;
}

void exercicio1(void) {
    int cpf[11];

    printf("Digite o CPF (somente numeros): ");
    for (int i = 0; i < 11; i++) {
        scanf("%1d", &cpf[i]);
    }

    int dv1 = calcularDigito(cpf, 9);

    
    int base[10];
    for (int i = 0; i < 9; i++) base[i] = cpf[i];
    base[9] = dv1;
    int dv2 = calcularDigito(base, 10);

    if (cpf[9] == dv1 && cpf[10] == dv2)
        printf("\nCPF VALIDO!");
    else
        printf("\nCPF INVALIDO!");
}

/* ---------- Exercício 2: Temperatura ---------- */

void exercicio2(void) {
    double celsius, fahrenheit;

    printf("Digite a temperatura em Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = celsius * 9.0 / 5.0 + 32;
    printf("A temperatura em Fahrenheit = %.2lf °F\n", fahrenheit);

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("A temperatura em Celsius = %.2lf °C\n", celsius);
}

/* ---------- Exercício 3: Média do aluno ---------- */

void exercicio3(void) {
    char nome[50];
    double notas[3];

    printf("Digite o nome do aluno: ");
    scanf("%s", nome);

    const char *ordem[3] = {"primeira", "segunda", "terceira"};
    double total = 0;
    for (int i = 0; i < 3; i++) {
        printf("Digite a %s nota: ", ordem[i]);
        scanf("%lf", &notas[i]);
        total += notas[i];
    }

    double media = total / 3;

    printf("\nAluno: %s", nome);
    printf("\nMedia: %.2lf\n", media);

    if (media >= 7) {
        printf("APROVADO(A)!");
    } else if (media >= 4) {
        printf("EXAME!");
        printf("\nFalta %.2lf pontos para chegar a 10.", 10 - media);
    } else {
        printf("REPROVADO(A)!");
    }
}

/* ---------- Exercício 4: Saque ---------- */

void exercicio4(void) {
    int restante;
    int cedulas[6] = {100, 50, 10, 5, 2, 1};
    int quantidade[6];

    printf("Digite o valor do saque: R$ ");
    scanf("%d", &restante);

    for (int i = 0; i < 6; i++) {
        quantidade[i] = restante / cedulas[i];
        restante      = restante % cedulas[i];
    }

    printf("\n RESUMO DO SAQUE \n");
    for (int i = 0; i < 6; i++) {
        printf("Notas de R$ %d: %d\n", cedulas[i], quantidade[i]);
    }
}

/* ---------- Exercício 5: Projétil ---------- */

void exercicio5(void) {
    float v0, angulo;

    printf("Velocidade Inicial? ");
    scanf("%f", &v0);

    printf("Angulo? ");
    scanf("%f", &angulo);

    float radianos = angulo * PI_APROX / 180;
    float vx = v0 * cos(radianos);
    float vy = v0 * sin(radianos);

    float t = 0, x = 0, y = 0;

    while (y >= 0) {
        t += 0.01f;

        float fator = 1 - exp(-ATRITO * t);

        x = (vx / ATRITO) * fator;
        y = (vy / ATRITO) * fator
            - (GRAVIDADE / ATRITO) * t
            + (GRAVIDADE / (ATRITO * ATRITO)) * fator;
    }

    printf("\nAlcance Maximo: %.2f metros\n", x);
    printf("Tempo de Voo: %.2f segundos\n", t);
}

/* ---------- Exercício 6: INSS ---------- */

void exercicio6(void) {
    float salario;

    printf("Valor do salario bruto? ");
    scanf("%f", &salario);

    printf("Desconto do INSS: %.2f\n", descontoINSS(salario));
}

/* ---------- Exercício 7: IRPF ---------- */

void exercicio7(void) {
    float salario;

    printf("Valor do salário base? ");
    scanf("%f", &salario);

    printf("Desconto do IRPF: %.2f\n", descontoIRPF(salario));
}

/* ---------- Exercício 8: Folha de pagamento ---------- */

void exercicio8(void) {
    float valorHora, horas;

    printf("Valor da hora trabalhada? ");
    scanf("%f", &valorHora);

    printf("Quantidade de horas no mês? ");
    scanf("%f", &horas);

    float bruto   = valorHora * horas;
    float inss    = descontoINSS(bruto);
    float irpf    = descontoIRPF(bruto);
    float liquido = bruto - inss - irpf;

    printf("\n========================================\n");
    printf("          CONTRA-CHEQUE\n");
    printf("========================================\n");
    printf("Salário Bruto:       R$ %.2f\n", bruto);
    printf("Desconto INSS:       R$ %.2f\n", inss);
    printf("Desconto IRPF:       R$ %.2f\n", irpf);
    printf("----------------------------------------\n");
    printf("Salário Líquido:     R$ %.2f\n", liquido);
    printf("========================================\n");
}

/* ---------- Programa principal ---------- */

int main(void) {
    int escolha;

    printf("\n========== MENU ==========\n");
    for (int i = 1; i <= 8; i++) {
        printf("%d - Exercício %d\n", i, i);
    }
    printf("Escolha o exercício: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: exercicio1(); break;
        case 2: exercicio2(); break;
        case 3: exercicio3(); break;
        case 4: exercicio4(); break;
        case 5: exercicio5(); break;
        case 6: exercicio6(); break;
        case 7: exercicio7(); break;
        case 8: exercicio8(); break;
        default: printf("Opção inválida!\n");
    }

    return 0;
}
