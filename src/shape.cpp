#include "shape.h"

void Shape::generate() {
  zbuffer = new std::vector<layer *>();

  for (int z = 0; z < depth; z++) {
    layer *current_layer = new layer();
    zbuffer->push_back(current_layer);

    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        const bool point = generation_algorithm(x, y, z);
        current_layer->push_back(point);
      }
    }
  }

  generated = true;
}

bool Shape::generation_algorithm(int x, int y, int z) { return false; }

layer *Shape::get_layer_at(int zindex) {
  try {
    return zbuffer->at(zindex);
  } catch (const std::exception &) {
    assert(false);
  }
}

void Shape::print_layer(int depth) {
  if (!generated) {
    assert(false);
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < height; x++) {
      layer *l = get_layer_at(depth);
      char s = l->at(x + y * height) ? sign : ' ';
      std::cout << s;
    }
    std::cout << '\n';
  }
}

std::string Shape::get_layer_as_string(int depth) {
  if (!generated) {
    assert(false);
  }

  std::string str = "";

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < height; x++) {
      layer *l = get_layer_at(depth);
      char s = l->at(x + y * height) ? sign : ' ';
      str += s;
    }
    str += '\n';
  }

  return str;
}

std::string Shape::get_as_string() {
  std::string str = "";

  for (int z = 0; z < depth; z++) {
    str += get_layer_as_string(z);
    // str += '\n';
  }

  return str;
}

void Shape::print() {
  for (int z = 0; z < depth; z++) {
    print_layer(z);
    std::cout << '\n';
  }
}

void Shape::write(std::string path) {
  std::ofstream file;
  file.open(path.c_str());

  std::string shape_as_string = get_as_string();

  file << shape_as_string;
  file.close();
}
