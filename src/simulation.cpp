#include "simulation.h"

Simulation::Simulation() {
  this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gravity Simulation"); 
  this->window->setFramerateLimit(30);
  body = Body();
}

void Simulation::update() {
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window->close();
  }
  body.update();
}

void Simulation::draw() {
  this->window->clear(sf::Color(46,68,130));
  body.draw(this->window);
  this->window->display();
}

bool Simulation::isOpen() {
  return this->window->isOpen();
}
