#pragma once
#include <SFML/Graphics.hpp>
#include <Food.hpp>

class Snake
{
public:
    Snake(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(20, 20));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color = sf::Color::Yellow);

        // Cargar la imagen desde un archivo

        if (!texture.loadFromFile("./assets/images/Snake sprite sheet.png"))
        {
            throw std::runtime_error("No se cargo la imagen");
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
                                            
    }
    void moveL(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
        sprite.setRotation(90);
    }
    void moveR(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
        sprite.setRotation(270);
    }
    void moveU(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
        sprite.setRotation(180);
    }
    void moveD(float offsetX, float offsetY)

    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
        sprite.setRotation(0);
    }
    void draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
    }
    void Update()
    {
        sprite.setTextureRect(sf::IntRect(1, 1, 45, 35));
    }
    
    bool DetectarColision(sf::FloatRect colision){
        return sprite.getGlobalBounds().intersects(colision);
    }
    

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
};
