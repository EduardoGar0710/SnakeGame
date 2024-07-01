#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <Box2D/Box2D.h>

class Snake
{
public:
    Snake(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color = sf::Color::Black);
          

        // Cargar la imagen desde un archivo
        
        if (!texture.loadFromFile("./assets/images/Snake sprite sheet.png"))
        {
            throw std::runtime_error("No se cargo la imagen");
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
     // Mapa
       

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

       // Paredes 
    

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
        window.draw(this->shape);
        window.draw(this->recorte);
        window.draw(this->sprite);
        
    }


void update(){

sprite.setTextureRect(sf::IntRect(1, 1, 50, 40));

}

private:
    sf::RectangleShape shape;
    sf::RectangleShape fondo;
    sf::Sprite sprite;
    sf::Sprite recorte;
    sf::Texture texture;
    sf::Texture mapa;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int frameWidth = 32;
    int frameHeight = 32;
};

double velocidad = 0.1;


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 499), "juegoSnake");

    Snake snake(sf::Vector2f(400, 300), sf::Color::Black);
  

   //Paredes 

    // Pared superior
    sf::RectangleShape techo(sf::Vector2f(800.0f, 10.0f));
    techo.setFillColor(sf::Color::Red);
    techo.setPosition(0.0f, 0.0f);

    // Pared inferior
    sf::RectangleShape bottomWall(sf::Vector2f(800.0f, 10.0f));
    bottomWall.setFillColor(sf::Color::Red);
    bottomWall.setPosition(0.0f, 590.0f);

    // Pared izquierda
    sf::RectangleShape leftWall(sf::Vector2f(10.0f, 600.0f));
    leftWall.setFillColor(sf::Color::Red);
    leftWall.setPosition(0.0f, 0.0f);

    // Pared derecha
    sf::RectangleShape rightWall(sf::Vector2f(10.0f, 600.0f));
    rightWall.setFillColor(sf::Color::Red);
    rightWall.setPosition(790.0f, 0.0f);
 // Reloj

  // sf::Clock clock;

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
      
      //Ver tiempo transcurrido 
       /* sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();*/
       
       //Mover serpiente

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            snake.moveL(velocidad * -1, 0);
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            snake.moveR(velocidad*1, 0);
           
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            snake.moveU(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            snake.moveD(0, velocidad*1);
        }

        /* Detectar colisiones con las paredes
        if (snake.getGlobalBounds().intersects(techo.getGlobalBounds())) {
            snake.setPosition(snake.getPosition().x, techo.getPosition().y + techo.getSize().y);
        }
        if (snake.getGlobalBounds().intersects(bottomWall.getGlobalBounds())) {
            snake.setPosition(player.getPosition().x, bottomWall.getPosition().y - player.getSize().y);
        }
        if (player.getGlobalBounds().intersects(leftWall.getGlobalBounds())) {
            player.setPosition(leftWall.getPosition().x + leftWall.getSize().x, player.getPosition().y);
        }
        if (player.getGlobalBounds().intersects(rightWall.getGlobalBounds())) {
            player.setPosition(rightWall.getPosition().x - player.getSize().x, player.getPosition().y);
        }*/

        // Actualizar mapa
        window.clear();
        snake.update();

        window.draw(techo);
        window.draw(bottomWall);
        window.draw(leftWall);
        window.draw(rightWall);
        snake.draw(window);   
        
        window.display();

    }

    return 0;
}