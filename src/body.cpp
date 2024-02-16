#include "body.h"
#include "simulation.h"
#include "randomizer.h"


Body::Body() {
  radius = Randomizer::Random(60.0f, 60.0f);
  position = sf::Vector2f(Randomizer::Random(radius, Simulation::WINDOW_WIDTH - radius),
      Randomizer::Random(radius, Simulation::WINDOW_HEIGHT - radius));
  velocity = sf::Vector2f(Randomizer::Random(-10.1f, 10.2f),
      Randomizer::Random(-10.1f, 10.2f));
  acceleration = sf::Vector2f(Randomizer::Random(0.1f, 0.2f),
      Randomizer::Random(0.1f, 0.2f));
  circle = sf::CircleShape(radius);
  circle.setRadius(radius);
  circle.setOrigin(radius, radius);
  circle.setPosition(position);
}

void Body::draw(sf::RenderWindow* window) {
  window->draw(circle); 
}

void Body::update() {
  bounce();
  //velocity += acceleration;
  position += velocity;
  adjust();
  circle.setPosition(position);
}


void Body::bounce() {
  // left wall
  if (!(circle.getRadius() < position.x && position.x + circle.getRadius() < Simulation::WINDOW_WIDTH)) {
    velocity.x *= -1;
    acceleration.x *= -1;
  }
  if (!(circle.getRadius() < position.y && position.y + circle.getRadius() < Simulation::WINDOW_HEIGHT)) {
    velocity.y *= -1;
    acceleration.y *= -1;
  }
}

void Body::adjust() {
  position.x = fmax(circle.getRadius(), position.x);
  position.y = fmax(circle.getRadius(), position.y);
  position.x = fmin(Simulation::WINDOW_WIDTH - circle.getRadius(), position.x);
  position.y = fmin(Simulation::WINDOW_HEIGHT - circle.getRadius(), position.y);
}
