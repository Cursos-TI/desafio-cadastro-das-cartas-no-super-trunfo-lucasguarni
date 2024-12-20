#include <stdio.h>

// Metodo que calcula a densidade populacional
float calculatePopulationDensity(int population, float area) {
    return population/area;
}

// Metodo que calcula o PIB per capita
float calculatePibPerCapita(int population, float pib) {
    return pib/population;
}

int main() {
    char name[100];
    int population, touristAttractions;
    float pib, pibPerCapita, area, populationDensity;

    printf("Iniciando cadastro de cidade \n\n");
    
    /*
        A expressao utilizada no scanf recupera valor digitado ate acontecer uma quebra de linha (\n). 
        Utilizando o %s a aplicacao quebra quando o nome da cidade tem mais de uma palavra. Como por exemplo Ribeirao Preto.
    */ 
    printf("Digite o nome da cidade: \n");
    scanf(" %[^\n]", name); 

    // Insere informacoes da populacao
    printf("Digite a população de %s:\n", name);
    scanf("%d", &population);

    // Insere dados da area
    printf("Digite a area de %s:\n", name);
    scanf("%f", &area);

    // Insere dados da PIB
    printf("Digite o PIB de %s:\n", name);
    scanf("%f", &pib);

    // Insere dados da quantidade de pontos turisticos
    printf("Digite a quantidade de pontos turísticos de %s:\n", name);
    scanf("%d", &touristAttractions);

    // Calculo de densidade populacional
    populationDensity = calculatePopulationDensity(population, area);
    // Calculo PIB per capita
    pibPerCapita = calculatePibPerCapita(population, pib);

    printf("Informacoes Gerais de %s: \n\n", name);
    printf("População: %d\n", population);
    printf("Area: %f\n", area);
    printf("Pib: %f\n", pib);
    printf("Numero de pontos turísticos: %d\n", touristAttractions);
    printf("Densidade Populacional: %f\n", populationDensity);
    printf("PIB per Capita: %f\n", pibPerCapita);
    
    return 0;
}
