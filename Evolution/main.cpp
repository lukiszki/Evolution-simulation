#include <SFML/Graphics.hpp>
#include "Creature.h"
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(200, 200), "Creatures");

    return 0;
}