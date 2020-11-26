#include <iostream>
#include "GameResources.cpp"

GameResources *gameResources;

int main() {
    printf("Loading...\n");
    gameResources = new GameResources();
    printf("Successfully injected! \\@.@/\n");

    float money = -1;
    int population = -1;

    while (true) {
        Sleep(500);
        float tmpMoney = money;
        int tmpPopulation = population;
        money = gameResources->GetMoney();
        population = gameResources->GetPopulation();

        if (money != tmpMoney) printf("You have $%f.\n", money);
        if (population != tmpPopulation) printf("You have a population of %d tropicans.\n", population);
    }
    return 0;
}