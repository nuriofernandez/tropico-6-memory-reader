#include <iostream>
#include "GameResources.cpp"

GameResources *gameResources;

int main() {
    printf("Loading...\n");
    gameResources = new GameResources();
    printf("Successfully injected! \\@.@/\n");

    float money = -1;
    int population = -1;
    int year = -1;
    int month = -1;
    bool paused;

    while (true) {
        Sleep(500);
        float tmpMoney = money;
        int tmpPopulation = population;
        int tmpYear = year;
        int tmpMonth = month;
        int tmpPaused = paused;
        money = gameResources->GetMoney();
        population = gameResources->GetPopulation();
        year = gameResources->GetYear();
        month = gameResources->GetMonth();
        paused = gameResources->IsPaused();

        if (money != tmpMoney) printf("You have $%f.\n", money);
        if (population != tmpPopulation) printf("You have a population of %d tropicans.\n", population);
        if (year != tmpYear) printf("You are in the year %d.\n", year);
        if (month != tmpMonth) printf("You are in the month %d.\n", month);
        if (paused != tmpPaused) printf("You game %s paused.\n", paused ? "is" : "is not");
    }
    return 0;
}