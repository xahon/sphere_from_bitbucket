#ifndef __POINT__
#define __POINT__

class Point {
public:
  Point() : x(0), y(0), z(0){};
  Point(int x, int y) : x(x), y(y), z(0){};
  Point(int x, int y, int z) : x(x), y(y), z(z){};

  const int x;
  const int y;
  const int z;
};

#endif
