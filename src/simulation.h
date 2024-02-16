#include <SFML/Graphics.hpp>

class Simulation {
private:
  sf::Event event;
  sf::RenderWindow* window;
public:
  Simulation();
  void update();
  void draw();
  bool isOpen();
};
