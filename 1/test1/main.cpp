
#include <clocale>
#include "game.h"


int main()
{
    //std::setlocale(LC_ALL, "");
    //setlocale(LC_CTYPE, "ru_RU.UTF-8"); // вызов функции настройки локали
    Game game;
    game.run();


    return EXIT_SUCCESS;
}
