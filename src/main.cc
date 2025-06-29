#include <iostream>
#include <string>

#include "circle.h"
#include "rectangle.h"
#include "sphere.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: crochet_pattern <shape> [params]" << std::endl;
    return 1;
  }

  std::string shape = argv[1];

  if (shape == "circle") {
    if (argc < 4) {
      std::cout << "Usage: crochet_pattern circle <radius> <yarn_thickness>"
                << std::endl;
      return 1;
    }
    double radius = std::stod(argv[2]);
    double yarn = std::stod(argv[3]);
    pattern::Circle::knot_type(radius, yarn);
  } else if (shape == "sphere") {
    if (argc < 4) {
      std::cout << "Usage: crochet_pattern sphere <radius> <yarn_thickness>"
                << std::endl;
      return 1;
    }
    double radius = std::stod(argv[2]);
    double yarn = std::stod(argv[3]);
    pattern::Sphere::knot_type(radius, yarn);
  } else if (shape == "rectangle") {
    if (argc < 5) {
      std::cout << "Usage: crochet_pattern rectangle <length> <width> "
                   "<yarn_thickness>"
                << std::endl;
      return 1;
    }
    double length = std::stod(argv[2]);
    double width = std::stod(argv[3]);
    double yarn = std::stod(argv[4]);
    pattern::Rectangle::knot_type(length, width, yarn);
  } else {
    std::cout << "Unknown shape: " << shape << std::endl;
    return 1;
  }

  return 0;
}