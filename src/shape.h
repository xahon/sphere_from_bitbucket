#include "assert.h"
#include "iostream"
#include "point.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#ifndef __SHAPE__
#define __SHAPE__

typedef std::vector<bool> layer;

class Shape {
public:
  Shape(char sign, int width, int height, int depth)
      : sign(sign), width(width), height(height), depth(depth){};

  ~Shape();

  layer *get_layer_at(int zindex);
  void place_at(Point origin, Shape &shape);
  virtual void generate() final;
  virtual std::string get_layer_as_string(int depth) final;
  virtual std::string get_as_string() final;
  virtual void print_layer(int depth) final;
  virtual void print() final;
  virtual void write(std::string path) final;

protected:
  virtual bool generation_algorithm(int x, int y, int z);
  int height;
  int width;
  int depth;

private:
  char sign;
  bool generated = false;
  std::vector<layer *> *zbuffer;
  std::vector<Shape *> children;
};

#endif
