#include <stdio.h>
#include <stdlib.h>

#define MAX_CARTAS 100    // Número máximo de cartas que podem ser cadastradas
#define MAX_ESTADO 50     // Tamanho máximo para a string do estado
#define MAX_NOME    100   // Tamanho máximo para a string do nome da cidade


typedef struct {
    char estado[MAX_ESTADO];
    int codigo;
    char nomeCidade[MAX_NOME];
    long long populacao;
    double pib;
    double area;
    int numPontosTuristicos;
    double densidade;       
    double pibPerCapita;    
} CartaCidade;

int main() {
    int n, i;

    printf("Quantas cartas de cidades você deseja cadastrar? ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_CARTAS) {
        printf("Quantidade inválida. Use um número entre 1 e %d.\n", MAX_CARTAS);
        return 1;
    }

    // Aloca um vetor estático de cartas (poderia ser dinâmico, mas para simplificar, usaremos tamanho fixo)
    CartaCidade cartas[MAX_CARTAS];

    for (i = 0; i < n; i++) {
        printf("\n=== Cadastro da Carta %d ===\n", i + 1);

        // Lê o estado (pode conter espaços)
        printf("Estado: ");
        scanf(" %49[^\n]", cartas[i].estado);

        // Lê o código (número inteiro)
        printf("Código da cidade: ");
        scanf("%d", &cartas[i].codigo);

        // Lê o nome da cidade (pode conter espaços)
        printf("Nome da cidade: ");
        scanf(" %99[^\n]", cartas[i].nomeCidade);

        // Lê a população
        printf("População (número inteiro): ");
        scanf("%lld", &cartas[i].populacao);

        // Lê o PIB (valor em ponto flutuante)
        printf("PIB (valor em ponto flutuante): ");
        scanf("%lf", &cartas[i].pib);

        // Lê a área (em km², por exemplo)
        printf("Área (em km², ponto flutuante): ");
        scanf("%lf", &cartas[i].area);

        // Lê o número de pontos turísticos
        printf("Número de pontos turísticos (inteiro): ");
        scanf("%d", &cartas[i].numPontosTuristicos);

        // Cálculo das propriedades derivadas:
        if (cartas[i].area > 0) {
            cartas[i].densidade = (double)cartas[i].populacao / cartas[i].area;
        } else {
            cartas[i].densidade = 0.0;  // evita divisão por zero
        }

        if (cartas[i].populacao > 0) {
            cartas[i].pibPerCapita = cartas[i].pib / (double)cartas[i].populacao;
        } else {
            cartas[i].pibPerCapita = 0.0;
        }
    }

    // Exibe todas as cartas cadastradas, incluindo campos derivados
    printf("\n\n===== Relatório de Cartas de Cidades =====\n");
    for (i = 0; i < n; i++) {
        printf("\n--- Carta %d ---\n", i + 1);
        printf("Estado: %s\n", cartas[i].estado);
        printf("Código: %d\n", cartas[i].codigo);
        printf("Nome da cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %lld\n", cartas[i].populacao);
        printf("PIB: %.2f\n", cartas[i].pib);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("Número de pontos turísticos: %d\n", cartas[i].numPontosTuristicos);
        printf("Densidade populacional: %.2f habitantes/km²\n", cartas[i].densidade);
        printf("PIB per capita: %.6f\n", cartas[i].pibPerCapita);
    }

    return 0;
}
