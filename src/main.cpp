#include <iostream>
#include "game/GameResources.cpp"

GameResources *tropico;

int main() {
    printf("Loading...\n");
    tropico = new GameResources();
    printf("Successfully injected! \\@.@/\n");

    float money = -1;
    int population = -1;
    float support = -1;
    int year = -1;
    int month = -1;
    bool paused;
    int unemployment = -1;
    int homeless = -1;

    while (true) {
        Sleep(500);
        float tmpMoney = money;
        int tmpPopulation = population;
        float tmpSupport = support;
        int tmpYear = year;
        int tmpMonth = month;
        bool tmpPaused = paused;
        int tmpUnemployment = unemployment;
        int tmpHomeless = homeless;

        money = tropico->GetMoney();
        //population = tropico->GetPopulation();
        //support = tropico->GetSupport();
        //year = tropico->GetYear();
        //month = tropico->GetMonth();
        //paused = tropico->IsPaused();
        //unemployment = tropico->GetUnemployedCitizens();
        //homeless = tropico->GetHomelessCitizens();

        if (money != tmpMoney) printf("You have $%f.\n", money);
        if (population != tmpPopulation) printf("You have a population of %d tropicans.\n", population);
        if (support != tmpSupport) printf("Your current support is %f.\n", support);
        if (year != tmpYear) printf("You are in the year %d.\n", year);
        if (month != tmpMonth) printf("You are in the month %d.\n", month);
        if (paused != tmpPaused) printf("You game %s paused.\n", paused ? "is" : "is not");
        if (unemployment != tmpUnemployment) printf("You have %d unemployed tropicans.\n", unemployment);
        if (homeless != tmpHomeless) printf("You have %d homeless tropicans.\n", homeless);
    }
    return 0;
}