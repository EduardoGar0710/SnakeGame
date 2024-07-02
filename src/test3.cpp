#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

// Constantes del juego
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int SNAKE_SIZE = 20;

enum Direction { Up, Down, Left, Right };

struct SnakeSegment {
    sf::RectangleShape shape;
    SnakeSegment(float x, float y) {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(SNAKE_SIZE, SNAKE_SIZE));
        shape.setFillColor(sf::Color::Green);
    }
};

class Snake {
public:
    Snake() {
        segments.push_back(SnakeSegment(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
        direction = Direction::Right;
    }

    void move() {
        sf::Vector2f previousPosition = segments[0].shape.getPosition();
        sf::Vector2f newPosition = previousPosition;

        switch (direction) {
            case Direction::Up:    newPosition.y -= SNAKE_SIZE; break;
            case Direction::Down:  newPosition.y += SNAKE_SIZE; break;
            case Direction::Left:  newPosition.x -= SNAKE_SIZE; break;
            case Direction::Right: newPosition.x += SNAKE_SIZE; break;
        }

        for (size_t i = segments.size() - 1; i > 0; --i) {
            segments[i].shape.setPosition(segments[i - 1].shape.getPosition());
        }

        segments[0].shape.setPosition(newPosition);
    }

    void grow() {
        sf::Vector2f tailPosition = segments.back().shape.getPosition();
        segments.push_back(SnakeSegment(tailPosition.x, tailPosition.y));
    }

    void setDirection(Direction dir) {
        direction = dir;
    }

    std::vector<SnakeSegment>& getSegments() {
        return segments;
    }

    sf::FloatRect getHeadBounds() {
        return segments[0].shape.getGlobalBounds();
    }

private:
    std::vector<SnakeSegment> segments;
    Direction direction;
};

sf::Vector2f getRandomPosition() {
    static std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
    static std::uniform_int_distribution<> disX(0, WINDOW_WIDTH / SNAKE_SIZE - 1);
    static std::uniform_int_distribution<> disY(0, WINDOW_HEIGHT / SNAKE_SIZE - 1);

    return sf::Vector2f(disX(gen) * SNAKE_SIZE, disY(gen) * SNAKE_SIZE);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
    window.setFramerateLimit(10);

    Snake snake;
    sf::RectangleShape food(sf::Vector2f(SNAKE_SIZE, SNAKE_SIZE));
    food.setFillColor(sf::Color::Red);
    food.setPosition(getRandomPosition());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
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
        if (snake.getHeadBounds().intersects(food.getGlobalBounds())) {
            snake.grow();
            food.setPosition(getRandomPosition());
        }

        // Dibujar el juego
        window.clear();
        for (auto& segment : snake.getSegments()) {
            window.draw(segment.shape);
        }
        window.draw(food);
        window.display();
    }

    return 0;
}
