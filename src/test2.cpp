#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Collision Detection");

    // Cargar texturas
    sf::Texture texture1;
    if (!texture1.loadFromFile("./assets/images/Snake sprite sheet.png")) {
        return -1;
    }

    sf::Texture texture2;
    if (!texture2.loadFromFile("./assets/images/apple.png")) {
        return -1;
    }

    // Crear sprites y asignarles las texturas
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);
    sprite1.setPosition(100, 100);

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setPosition(200, 200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movimiento de ejemplo para el sprite1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            sprite1.move(-0.1f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            sprite1.move(0.1f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            sprite1.move(0.0f, -0.1f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            sprite1.move(0.0f, 0.1f);

        // Detectar colisión
        if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds())) {
            sprite1.setColor(sf::Color::Red); // Cambiar el color del sprite1 en caso de colisión
          std::cout<<"Colision con techo"<<std::endl;
        } else {
            sprite1.setColor(sf::Color::White); // Restaurar el color del sprite1 si no hay colisión
        }

        window.clear();
        window.draw(sprite1);
        window.draw(sprite2);
        window.display();
    }

    return 0;
}
