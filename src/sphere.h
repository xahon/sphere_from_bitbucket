#include "assert.h"
#include "point.h"
#include "shape.h"
#include <iostream>
#include <math.h>
#include <vector>

#ifndef __SPHERE__
#define __SPHERE__

class Sphere : public Shape {
public:
  Sphere(char sign, int radius)
      : Shape(sign, radius * 2 + 1, radius * 2 + 1, radius * 2 + 1),
        radius(radius){};
  ~Sphere();

protected:
  bool generation_algorithm(int x, int y, int z) {
    const Point center(width / 2, height / 2, depth / 2);
    const int xpow = (int)pow((double)x - center.x, 2);
    const int ypow = (int)pow((double)y - center.y, 2);
    const int zpow = (int)pow((double)z - center.z, 2);
    const int rpow = (int)pow((double)radius, 2);

    if (xpow + ypow + zpow <= rpow) {
      return true;
    }

    return false;
  };

private:
  int radius;
  std::vector<layer *> *zbuffer;
  std::vector<Sphere *> children;
};

#endif
