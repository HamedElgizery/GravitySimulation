#include "simulation.h"

Simulation::Simulation() {
  this->window = new sf::RenderWindow(sf::VideoMode(3000, 1500), "Gravity Simulation"); 
}

void Simulation::update() {
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window->close();
  }
  this->window->clear(sf::Color(46,68,130));
}

void Simulation::draw() {
  this->window->display();
}

bool Simulation::isOpen() {
  return this->window->isOpen();
}
