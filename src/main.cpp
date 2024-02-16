#include <iostream>
#include "simulation.h"

int main() {
  std::cout << "Program starting...\n";
  Simulation simulation;
  while (simulation.isOpen()) {
    simulation.update();
    simulation.draw();
  }
  return 0;
}
