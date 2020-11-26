#include <iostream>
#include "GameResources.cpp"

GameResources *gameResources;

int main() {
    printf("Loading...\n");
    gameResources = new GameResources();
    printf("Successfully injected! \\@.@/\n");

    float money = gameResources->GetMoney();
    printf("You have $%f.\n", money);

    gameResources->SetMoney(money+150000);
    printf("Now you have $%f.\n", money+150000);

    return 0;
}