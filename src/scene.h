#include "assert.h"
#include "point.h"
#include "shape.h"
#include <iostream>
#include <vector>

#ifndef __SCENE__
#define __SCENE__

class Scene : public Shape {
public:
  Scene(int width, int height, int depth) : Shape('0', width, height, depth){};
  ~Scene();

protected:
  bool generation_algorithm(int x, int y, int z);

private:
  std::vector<layer *> *zbuffer;
  std::vector<Scene *> children;
};

#endif
