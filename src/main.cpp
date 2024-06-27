#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
     // Crear una ventana de SFML
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    
     // Crear una forma rectangular de SFML
    sf::RectangleShape rectangle(sf::Vector2f(120, 60));
    rectangle.setFillColor(sf::Color::Green);

     while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Verificar si se ha cerrado la ventana
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar la forma en la ventana
        window.draw(rectangle);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}
