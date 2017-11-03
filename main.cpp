#include "src/sphere.h"
#include <iostream>

int main(int argc, char **argv) {
  Sphere *sphere = new Sphere('X', 20);
  sphere->generate();
  sphere->write("sphere.txt");
  return 0;
}
