#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <Box2D/Box2D.h>
#include <Mapa.hpp>
#include <iostream>
#include <Food.hpp>
#include <cstdlib>
#include <ctime>
#include <Serpiente.hpp>


double velocidad = 0.3;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 499), "juegoSnake");

    Serpiente snake(sf::Vector2f(400, 300), sf::Color::Yellow);
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

             if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:    snake.setDirection(Direction::Up); break;
                    case sf::Keyboard::Down:  snake.setDirection(Direction::Down); break;
                    case sf::Keyboard::Left:  snake.setDirection(Direction::Left); break;
                    case sf::Keyboard::Right: snake.setDirection(Direction::Right); break;
                    default: break;
                }
            }
        }

        snake.move();
          // Detectar colisión con la comida
        if (snake.getHeadBounds().intersects(food.food.getGlobalBounds())) {
            snake.grow();
            food.setPosition(getRandomPosition());
        }

        // Ver tiempo transcurrido
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        // Mover serpiente

       
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