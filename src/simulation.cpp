#include "simulation.h"

Simulation::Simulation() {
  this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gravity Simulation"); 
  this->window->setFramerateLimit(60);
  for (int i = 0; i < 2; ++i) {
    bodies.push_back(Body());
  }
}

void Simulation::update() {
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window->close();
  }
  for (auto& body : bodies) body.update();
  for (int i = 0; i < bodies.size(); ++i) {
    sf::Vector2f acceleration;
    for (int j = 0; j < bodies.size(); ++j) {
      if(i == j) continue;
      if (bodies[i].collides(bodies[j])) {
        bodies[i].processCollision(bodies[j]);
      }
      float r = bodies[i].distance(bodies[j].getPosition());
      // TODO:: change to getMass
      float f = G * bodies[i].getRadius() * bodies[j].getRadius() / (r * r);
      float a = f / bodies[i].getRadius();
      float dy = bodies[i].getPosition().y - bodies[j].getPosition().y;
      float dx = bodies[i].getPosition().x - bodies[j].getPosition().x;
      float cos_res = dx / r;
      float sin_res = dy / r;
      sf::Vector2f temp_acceleration(-1e12 * a * cos_res, -1e12 * a * sin_res);
      acceleration += temp_acceleration;
    }
    bodies[i].setAcceleration( acceleration);
    //std::cout << "Body #" << i << ": " << acceleration.x << ' ' << acceleration.y << std::endl;
  }
}

void Simulation::draw() {
  this->window->clear(sf::Color(11, 16, 38));
  for (auto& body : bodies) body.draw(this->window);
  this->window->display();
}

bool Simulation::isOpen() {
  return this->window->isOpen();
}
