#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>

class Food
{
private:
    sf::Texture mapa;
    
    
public:
sf::Sprite food;
float objectSize = 50.0f;

public:

    sf::Vector2f getRandomPosition(sf::RenderWindow& window, float objectSize) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> disX(0, window.getSize().x - static_cast<int>(objectSize));
    static std::uniform_int_distribution<> disY(0, window.getSize().y - static_cast<int>(objectSize));

    float x = static_cast<float>(disX(gen));
    float y = static_cast<float>(disY(gen));
    return sf::Vector2f(x, y);
}

    Food(sf::Vector2f position, sf::Color color)
    {

         sf::RenderWindow window(sf::VideoMode(600, 450), "Random Object Example");
        // Cargar la imagen desde un archivo

        if (!mapa.loadFromFile("./assets/images/apple.png"))
        {
            throw std::runtime_error("No se cargo la imagen");
        }
        this->food = sf::Sprite(mapa);
        this->food.setPosition(getRandomPosition(window, objectSize));
    }

    void draw(sf::RenderWindow &window){
    window.draw(this->food);
    }
   
   
};
 