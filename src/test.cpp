#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>


// Función para generar una posición aleatoria
sf::Vector2f getRandomPosition(sf::RenderWindow& window, float objectSize) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> disX(0, window.getSize().x - static_cast<int>(objectSize));
    static std::uniform_int_distribution<> disY(0, window.getSize().y - static_cast<int>(objectSize));

    float x = static_cast<float>(disX(gen));
    float y = static_cast<float>(disY(gen));
    return sf::Vector2f(x, y);
}

int main() {
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Random Object Example");

    // Tamaño del objeto
    float objectSize = 50.0f;

    // Crear un objeto (círculo)
    sf::CircleShape circle(objectSize / 2);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(getRandomPosition(window, objectSize));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Detectar colisión con el cursor del ratón
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::FloatRect circleBounds = circle.getGlobalBounds();

            if (circleBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                circle.setPosition(getRandomPosition(window, objectSize));
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
