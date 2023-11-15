#include <ctime>

#include "game/game.h"

int main() {
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Game game;
    game.StartGame();

    return 0;
}
