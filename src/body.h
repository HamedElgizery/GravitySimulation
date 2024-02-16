#ifndef BODY
#define BODY

#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include <iostream>

class Body {
  private:
    sf::Vector2f position; 
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::CircleShape circle;
    float radius;
  public:
    Body();
    void draw(sf::RenderWindow*);
    void update();
};

#endif
