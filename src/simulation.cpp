#include "simulation.h"

Simulation::Simulation() {
  this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gravity Simulation"); 
  this->window->setFramerateLimit(30);
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
    for (int j = i + 1; j < bodies.size(); ++j) {
      if (bodies[i].collides(bodies[j])) std::cout << "Collision detected\n";
    }
  }
}

void Simulation::draw() {
  this->window->clear(sf::Color(46,68,130));
  for (auto& body : bodies) body.draw(this->window);
  this->window->display();
}

bool Simulation::isOpen() {
  return this->window->isOpen();
}
