#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::Clock clock;
    int count = 0;
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        count++;
        if (clock.getElapsedTime().asMilliseconds() > 1000)
        {
            std::cout << count << "\n";
            count = 0;
            clock.restart();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}