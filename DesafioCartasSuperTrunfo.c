#include <stdio.h>
#include <string.h>

#define MAX_ESTADO 50
#define MAX_NOME   100

typedef struct {
    char estado[MAX_ESTADO];
    int codigo;
    char nomeCidade[MAX_NOME];
    unsigned long int populacao;
    double pib;
    double area;
    int numPontosTuristicos;
    double densidade;        
    double pibPerCapita;     
    float superPoder;        
} Carta;


void lerCarta(Carta *c) {
    printf("Estado: ");
    scanf(" %49[^\n]", c->estado);

    printf("Código da cidade: ");
    scanf("%d", &c->codigo);

    printf("Nome da cidade: ");
    scanf(" %99[^\n]", c->nomeCidade);

    printf("População (unsigned long int): ");
    scanf("%lu", &c->populacao);

    printf("PIB (double): ");
    scanf("%lf", &c->pib);

    printf("Área (double, em km²): ");
    scanf("%lf", &c->area);

    printf("Número de pontos turísticos (int): ");
    scanf("%d", &c->numPontosTuristicos);
}

void calcularDerivados(Carta *c) {
    if (c->area > 0.0)
        c->densidade = (double)c->populacao / c->area;
    else
        c->densidade = 0.0;  /* evita divisão por zero */

    if (c->populacao > 0UL)
        c->pibPerCapita = c->pib / (double)c->populacao;
    else
        c->pibPerCapita = 0.0;
}

void calcularSuperPoder(Carta *c) {
    double invDensidade;

    if (c->densidade > 0.0)
        invDensidade = 1.0 / c->densidade;
    else
        invDensidade = 0.0;
    
    c->superPoder =
        (float)c->populacao +
        (float)c->area +
        (float)c->pib +
        (float)c->numPontosTuristicos +
        (float)c->pibPerCapita +
        (float)invDensidade;
}

int main() {
    Carta carta1, carta2;

    printf("=== Batalha de Cartas no Super Trunfo ===\n\n");

    /* Leitura das duas cartas */
    printf("Cadastre os dados da Carta 1:\n");
    lerCarta(&carta1);
    printf("\nCadastre os dados da Carta 2:\n");
    lerCarta(&carta2);

    /* Cálculo de densidade e PIB per capita */
    calcularDerivados(&carta1);
    calcularDerivados(&carta2);

    /* Cálculo do Super Poder */
    calcularSuperPoder(&carta1);
    calcularSuperPoder(&carta2);

    /* Comparações atributo por atributo */
    int winPop, winArea, winPIB, winPontos, winDens, winPIBpc, winSP;

    /* População: maior vence */
    winPop = (carta1.populacao > carta2.populacao) ? 1 : 0;

    /* Área: maior vence */
    winArea = (carta1.area > carta2.area) ? 1 : 0;

    /* PIB: maior vence */
    winPIB = (carta1.pib > carta2.pib) ? 1 : 0;

    /* Pontos Turísticos: maior vence */
    winPontos = (carta1.numPontosTuristicos > carta2.numPontosTuristicos) ? 1 : 0;

    /* Densidade Populacional: menor vence */
    winDens = (carta1.densidade < carta2.densidade) ? 1 : 0;

    /* PIB per Capita: maior vence */
    winPIBpc = (carta1.pibPerCapita > carta2.pibPerCapita) ? 1 : 0;

    /* Super Poder: maior vence */
    winSP = (carta1.superPoder > carta2.superPoder) ? 1 : 0;

    /* Exibição dos resultados */
    printf("\nComparação de Cartas:\n\n");

    if (winPop)
        printf("População:         Carta 1 venceu (%d)\n\n", winPop);
    else
        printf("População:         Carta 2 venceu (%d)\n\n", winPop);

    if (winArea)
        printf("Área:              Carta 1 venceu (%d)\n\n", winArea);
    else
        printf("Área:              Carta 2 venceu (%d)\n\n", winArea);

    if (winPIB)
        printf("PIB:               Carta 1 venceu (%d)\n\n", winPIB);
    else
        printf("PIB:               Carta 2 venceu (%d)\n\n", winPIB);

    if (winPontos)
        printf("Pontos Turísticos: Carta 1 venceu (%d)\n\n", winPontos);
    else
        printf("Pontos Turísticos: Carta 2 venceu (%d)\n\n", winPontos);

    if (winDens)
        printf("Densidade Pop.:    Carta 1 venceu (%d)\n\n", winDens);
    else
        printf("Densidade Pop.:    Carta 2 venceu (%d)\n\n", winDens);

    if (winPIBpc)
        printf("PIB per Capita:    Carta 1 venceu (%d)\n\n", winPIBpc);
    else
        printf("PIB per Capita:    Carta 2 venceu (%d)\n\n", winPIBpc);

    if (winSP)
        printf("Super Poder:       Carta 1 venceu (%d)\n", winSP);
    else
        printf("Super Poder:       Carta 2 venceu (%d)\n", winSP);

    return 0;
}
