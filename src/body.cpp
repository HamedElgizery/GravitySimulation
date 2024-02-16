#include "body.h"
#include "simulation.h"
#include "randomizer.h"

Body::Body() {
  radius = Randomizer::Random(20.0f, 40.0f);
  position = sf::Vector2f(Randomizer::Random(radius, Simulation::WINDOW_WIDTH - radius),
      Randomizer::Random(radius, Simulation::WINDOW_HEIGHT - radius));
  velocity = sf::Vector2f(Randomizer::Random(0.1f, 0.5f),
      Randomizer::Random(0.1f, 0.5f));
  acceleration = sf::Vector2f(Randomizer::Random(0.1f, 0.5f),
      Randomizer::Random(0.1f, 0.5f));
  circle = sf::CircleShape(radius);
  circle.setPosition(position);
  circle.setRadius(radius);
}

void Body::draw(sf::RenderWindow* window) {
  window->draw(circle); 
}

void Body::update() {
  velocity += acceleration;
  position += velocity;
  circle.setPosition(position);
}

