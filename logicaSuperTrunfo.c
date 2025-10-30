#include <stdio.h>
#include <string.h> // Adicionado para a função strcpy

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Implementação: Nível Aventureiro (Menu Switch) com tipo 'int' para População.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    
    // Variáveis para a Carta 1
    char estado1[60];
    char codigo_carta1[10];
    char cidade1[50];
    int populacao1; // Usando int
    float area1;
    float pib1;
    int pontos_turisticos1;

    // Variáveis para a Carta 2
    char estado2[60];
    char codigo_carta2[10];
    char cidade2[50];
    int populacao2; // Usando int
    float area2;
    float pib2;
    int pontos_turisticos2;

    // Variáveis para a lógica de comparação
    float densidade1, densidade2;
    int escolha;
    float valor_carta1, valor_carta2;
    char nome_atributo[50];
    
    // Cadastro das Cartas:
    
    // Coleta de dados da Carta 1
    printf("--- CADASTRO DA CARTA 1 ---\n");
    printf("Digite o nome do estado: ");
    scanf(" %59[^\n]", estado1);
    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", codigo_carta1);
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", cidade1);
    printf("Digite a populacao (Use int): ");
    scanf("%d", &populacao1); 
    printf("Digite a area em km2 (Use ponto): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhoes, use ponto): ");
    scanf("%f", &pib1);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);

    // Coleta de dados da Carta 2
    printf("\n--- CADASTRO DA CARTA 2 ---\n");
    printf("Digite o nome do estado: ");
    scanf(" %59[^\n]", estado2);
    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%s", codigo_carta2);
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", cidade2);
    printf("Digite a populacao (Use int): ");
    scanf("%d", &populacao2); 
    printf("Digite a area em km2 (Use ponto): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes, use ponto): ");
    scanf("%f", &pib2);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // Comparação de Cartas:

    // 1. Cálculo da Densidade
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    printf("\n\n--- DUELO FINAL: %s vs %s ---\n", cidade1, cidade2);
    
    // 2. Menu Interativo
    printf("\n--- Escolha o atributo para comparar ---\n");
    printf("1. Populacao (Maior valor vence)\n");
    printf("2. Area (Maior valor vence)\n");
    printf("3. PIB (Maior valor vence)\n");
    printf("4. Pontos Turisticos (Maior valor vence)\n");
    printf("5. Densidade Demografica (Menor valor vence - Super Trunfo)\n");
    printf("\nDigite sua escolha (1-5): ");
    scanf("%d", &escolha);

    // 3. Seleção de valores (switch)
    switch (escolha) {
        case 1: 
            strcpy(nome_atributo, "Populacao"); 
            valor_carta1 = (float)populacao1; 
            valor_carta2 = (float)populacao2; 
            break;
        case 2: 
            strcpy(nome_atributo, "Area"); 
            valor_carta1 = area1; 
            valor_carta2 = area2; 
            break;
        case 3: 
            strcpy(nome_atributo, "PIB"); 
            valor_carta1 = pib1; 
            valor_carta2 = pib2; 
            break;
        case 4: 
            strcpy(nome_atributo, "Pontos Turisticos"); 
            valor_carta1 = (float)pontos_turisticos1; 
            valor_carta2 = (float)pontos_turisticos2; 
            break;
        case 5: 
            strcpy(nome_atributo, "Densidade Demografica"); 
            valor_carta1 = densidade1; 
            valor_carta2 = densidade2; 
            break;
        default: 
            printf("Opcao invalida! Fim de jogo.\n"); 
            return 1;
    }
    
    // 4. Comparação (if/else)
    printf("\n\n--- DUELO DE ATRIBUTO: %s ---\n", nome_atributo);
    printf("Valor de %s: %.2f\n", cidade1, valor_carta1);
    printf("Valor de %s: %.2f\n", cidade2, valor_carta2);
    printf("----------------------------------\n");

    char* cidade_vencedora;
    float valor_vencedor;
    
    if (escolha == 5) { // Regra especial: MENOR valor vence
        if (valor_carta1 < valor_carta2) {
            cidade_vencedora = cidade1;
            valor_vencedor = valor_carta1;
        } else if (valor_carta2 < valor_carta1) {
            cidade_vencedora = cidade2;
            valor_vencedor = valor_carta2;
        } else {
            cidade_vencedora = "Empate";
        }
    } else { // Regra geral: MAIOR valor vence
        if (valor_carta1 > valor_carta2) {
            cidade_vencedora = cidade1;
            valor_vencedor = valor_carta1;
        } else if (valor_carta2 > valor_carta1) {
            cidade_vencedora = cidade2;
            valor_vencedor = valor_carta2;
        } else {
            cidade_vencedora = "Empate";
        }
    }

    // Exibição dos Resultados:
    
    printf("\n--- Veredito Final ---\n");
    if (strcmp(cidade_vencedora, "Empate") == 0) {
        printf("Resultado: Empate! Ambas tem o mesmo valor (%.2f) no atributo %s.\n", valor_carta1, nome_atributo);
    } else {
        printf("A carta vencedora e %s, com o valor de %.2f no atributo %s!\n",
               cidade_vencedora, valor_vencedor, nome_atributo);
    }

    return 0;
}