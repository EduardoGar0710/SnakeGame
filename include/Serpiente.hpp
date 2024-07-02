#pragma once
#include <SFML/Graphics.hpp>
#include <deque>

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

class Serpiente {
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