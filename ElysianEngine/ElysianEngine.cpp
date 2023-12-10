#include "Game.h"
#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::cout << "Hello World!\n";
    Game* game = new Game("Ziggy's Folly");

    std::cout << "Game ID: " << game->GetId();

    game->Initialize();
    game->RunLoop();

    delete game;

    return 0;
}
