#include <iostream>
#include "GameResources.cpp"

GameResources *gameResources;

int main() {
    printf("Loading...\n");
    gameResources = new GameResources();
    printf("Successfully injected! \\@.@/\n");

    float money = gameResources->GetMoney();
    printf("You have $%f.\n", money);

    int population = gameResources->GetPopulation();
    printf("You have a population of %d tropicans.\n", population);

    return 0;
}