#ifndef BODY
#define BODY

#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include <iostream>
#include <algorithm>

class Body {
  private:
    sf::Vector2f position; 
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::CircleShape circle;
    float radius;
    float mass; // equal radius for now
  public:
    Body();
    void draw(sf::RenderWindow*);
    void update();
    void adjust();
    void bounce();
    sf::Vector2f getPosition() const;
    sf::Vector2f getVelocity() const;
    sf::Vector2f getAcceleration() const; 
    float getRadius() const;
    void setPosition(sf::Vector2f);
    void setVelocity(sf::Vector2f);
    void setAcceleration(sf::Vector2f);
    void setRadius(float);
    float distance(sf::Vector2f);
    bool collides(const Body&);
};

#endif
