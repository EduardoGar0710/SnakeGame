#include <SFML/Graphics.hpp>
#include <stdexcept>

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
        window.draw(this->sprite);
    }


void update(){

sprite.setTextureRect(sf::IntRect(1, 1, 50, 40));

}

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Número total de frames en la animación
    int frameWidth = 32;
    int frameHeight = 32;
};

double velocidad = 0.2;

class Mapa{

public:
   
    Mapa(sf::Vector2f position, sf::Color color)
    {
        formaMapa.setSize(sf::Vector2f(50, 50));
        formaMapa.setPosition(position); // Posición inicial cuadro
        formaMapa.setFillColor(color = sf::Color::Black);
          

        // Cargar la imagen desde un archivo
        
        if (!textura.loadFromFile("./assets/images/mapa.png"))
        {
            throw std::runtime_error("No se cargo la imagen");
        }
        this->recorte = sf::Sprite(textura);
        this->recorte.setPosition(position); // Posición inicial sprite
    }
    void Cargar(){

    formaMapa.setTextureRect(sf::IntRect(1, 1,640, 499));

    }
    
     void draw(sf::RenderWindow &window)
    {
        window.draw(this->formaMapa);
        window.draw(this->recorte);
    }

    private:
    sf::RectangleShape formaMapa;
    sf::Sprite recorte;
    sf::Texture textura;
    sf::Clock clock;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DinoChrome");

    Snake snake(sf::Vector2f(400, 300), sf::Color::Red);
    Mapa  mapa (sf::Vector2f(400, 300), sf::Color::Yellow);

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

        // Actualizar animacion pikachu
        snake.update();
        window.clear();
        snake.draw(window);
        window.display();

        //mapa.Cargar();
        //mapa.draw(window);
       // window.display();


    }

    return 0;
}