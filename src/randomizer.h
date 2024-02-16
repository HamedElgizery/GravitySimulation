#ifndef RANDOMIZER
#define RANDOMIZER
#include <random>
#include <ctime>

class Randomizer {
  static std::mt19937 rnd;
  public:
  static int Random(int l, int r) {
    return l + rnd() % (r - l + 1);
  }
  static float Random(float l, float r) {
    return l + (r - l + 1) * (rnd() % 101) / 100.0;
  }
  
};

#endif
