#pragma once
#include <SFML/Graphics.hpp>

class Mapa
{
private:
    sf::RectangleShape fondo;
    sf::Sprite recorte;
    sf::Texture mapa;

public:
    Mapa(sf::Vector2f position, sf::Color color)
    {
        fondo.setSize(sf::Vector2f(640, 499));
        fondo.setPosition(position); // Posición inicial cuadro
        fondo.setFillColor(color = sf::Color::Yellow);

        // Cargar la imagen desde un archivo

        if (!mapa.loadFromFile("./assets/images/mapa.png"))
        {
            throw std::runtime_error("No se cargo la imagen");
        }
        this->recorte = sf::Sprite(mapa);
        this->recorte.setPosition(sf::Vector2f(0.0f, 0.0f));
    }

    void draw(sf::RenderWindow &window){
    window.draw(this->recorte);
    }
};
 