#include <stdio.h>
#include <string.h>

// Estrutura que representa a carta de cidade
typedef struct {
    char name[100];
    unsigned long int population;
    int touristAttractions;
    float pib, pibPerCapita, area, populationDensity, superPower;
} City;

// Metodo que calcula a densidade populacional
float calculatePopulationDensity(int population, float area) {
    return population/area;
}

// Metodo que calcula o PIB per capita
float calculatePibPerCapita(int population, float pib) {
    return pib/population;
}

// Metodo que calcula o super poder da cidade
float calculateSuperPower(City city) {
    return city.population + city.touristAttractions + city.pib + city.pibPerCapita + city.area + city.populationDensity;
}

City setCity() {
    City city;
    printf("Digite o nome da cidade: \n");
    fgets(city.name, sizeof(city.name), stdin);

    // Remove o caractere de nova linha
    city.name[strcspn(city.name, "\n")] = '\0'; 

    // Insere informacoes da populacao
    printf("Digite a população de %s:\n", city.name);
    scanf("%lu", &city.population);

    // Insere dados da area
    printf("Digite a area de %s:\n", city.name);
    scanf("%f", &city.area);

    // Insere dados da PIB
    printf("Digite o PIB de %s:\n", city.name);
    scanf("%f", &city.pib);

    // Insere dados da quantidade de pontos turisticos
    printf("Digite a quantidade de pontos turísticos de %s:\n", city.name);
    scanf("%d", &city.touristAttractions);

    // Limpa o buffer de entrada
    while (getchar() != '\n');

    // Calculo de densidade populacional
    city.populationDensity = calculatePopulationDensity(city.population, city.area);

    // Calculo PIB per capita
    city.pibPerCapita = calculatePibPerCapita(city.population, city.pib);

    // Calculo do super poder
    city.superPower = calculateSuperPower(city);

    // Exibe todas as informações
    printf("Informacoes Gerais de %s: \n\n", city.name);
    printf("População: %lu\n", city.population);
    printf("Area: %f\n", city.area);
    printf("Pib: %f\n", city.pib);
    printf("Numero de pontos turísticos: %d\n", city.touristAttractions);
    printf("Densidade Populacional: %f\n", city.populationDensity);
    printf("PIB per Capita: %f\n", city.pibPerCapita);
    printf("Super Poder: %f\n", city.superPower);

    return city;
}

int main() {
    City city1, city2;

    printf("Cartas SuperTrufo de cidades:\n\n");

    printf("Cadastro da primeira carta:\n");
    city1 = setCity();

    printf("\nCadastro da segunda carta:\n");
    city2 = setCity();

    printf("\nResultado da partida:\n");

    if (city1.population > city2.population) {
        printf("A carta %s tem a maior população\n", city1.name);
    } else {
        printf("A carta %s tem a maior população\n", city2.name);
    }

    if (city1.area > city2.area) {
        printf("A carta %s tem a maior área\n", city1.name);
    } else {
        printf("A carta %s tem a maior área\n", city2.name);
    }

    if(city1.pib > city2.pib) {
        printf("A carta %s tem o maior PIB\n", city1.name);
    } else {
        printf("A carta %s tem o maior PIB\n", city2.name);
    }

    if (city1.touristAttractions > city2.touristAttractions) {
        printf("A carta %s tem mais pontos turísticos\n", city1.name);
    } else {
        printf("A carta %s tem mais pontos turísticos\n", city2.name);
    }

    if(city1.populationDensity < city2.populationDensity) {
        printf("A carta %s tem a maior densidade populacional\n", city1.name);
    } else {
        printf("A carta %s tem a maior densidade populacional\n", city2.name);
    }

    if(city1.pibPerCapita > city2.pibPerCapita) {
        printf("A carta %s tem o maior PIB per capita\n", city1.name);
    } else {
        printf("A carta %s tem o maior PIB per capita\n", city2.name);
    }

    if(city1.superPower > city2.superPower) {
        printf("A carta %s tem o maior super poder\n", city1.name);
    } else {
        printf("A carta %s tem o maior super poder\n", city2.name);
    }
    
    return 0;
}
