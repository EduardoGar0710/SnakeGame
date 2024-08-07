#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <Box2D/Box2D.h>
#include <Mapa.hpp>
#include <iostream>
#include <Snake.hpp>
#include <Food.hpp>
#include <cstdlib>
#include <ctime>


double velocidad = 0.3;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 499), "juegoSnake");

    Snake snake(sf::Vector2f(400, 300), sf::Color::Yellow);
    Mapa mapa(sf::Vector2f(400, 300), sf::Color::Black);
    Food food(sf::Vector2f(400, 300), sf::Color::Black);

    sf::FloatRect circleBounds = food.food.getGlobalBounds();
    // Paredes

    // Reloj
    sf::Clock clock;

    // Crear paredes utilizando sf::RectangleShape
    
    // Pared superior
    sf::RectangleShape techo(sf::Vector2f(640.0f, 10.0f));
    techo.setFillColor(sf::Color::Black);
    techo.setPosition(0.0f, 25.0f);

    // Pared inferior
    sf::RectangleShape piso(sf::Vector2f(800.0f, 10.0f));
    piso.setFillColor(sf::Color::Black);
    piso.setPosition(0.0f, 488.0f);

    // Pared izquierda
    sf::RectangleShape paredIzquierda(sf::Vector2f(10.0f, 600.0f));
    paredIzquierda.setFillColor(sf::Color::Black);
    paredIzquierda.setPosition(5.0f, 25.0f);

    // Pared derecha
    sf::RectangleShape paredDerecha(sf::Vector2f(10.0f, 600.0f));
    paredDerecha.setFillColor(sf::Color::Black);
    paredDerecha.setPosition(627.0f, 25.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Ver tiempo transcurrido
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        // Mover serpiente

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            snake.moveL(velocidad * -1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            snake.moveR(velocidad * 1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            snake.moveU(0, velocidad * -1);

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            snake.moveD(0, velocidad * 1);
        }

        // Detectar colisiones con las paredes

        if (snake.DetectarColision(techo.getGlobalBounds()))
        {
            std::cout << "Colision con techo" << std::endl;
            window.close();
        }
        if (snake.DetectarColision(piso.getGlobalBounds()))
        {
            std::cout << "Colision con piso" << std::endl;
            window.close();
        }
        if (snake.DetectarColision(paredIzquierda.getGlobalBounds()))
        {
            std::cout << "Colision con paredIzquierda" << std::endl;
            window.close();
        }
        if (snake.DetectarColision(paredDerecha.getGlobalBounds()))
        {
            std::cout << "Colision con paredDerecha " << std::endl;
            window.close();
        }
        
        if (snake.DetectarColision(food.food.getGlobalBounds()))
        {
            std::cout << "Colision con cuadro " << std::endl;
          food.food.setPosition(food.getRandomPosition(window, food.objectSize));
         
            
        }


        // Actualizar mapa
        window.clear();
        snake.Update();
        mapa.draw(window);
        snake.draw(window);
        food.draw(window);

        // Dibujar las paredes
        window.draw(techo);
        window.draw(piso);
        window.draw(paredIzquierda);
        window.draw(paredDerecha);

        window.display();
    }

    return 0;
}