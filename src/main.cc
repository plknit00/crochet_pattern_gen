#include <iostream>
#include <string>

#include "circle.h"
#include "rectangle.h"
#include "sphere.h"

// using namespace pattern;

int main(int argc, char* argv[]) {
  if (argc < 5) {
    std::cerr << "Usage:\n";
    std::cerr << "For circle/sphere: crochet_pattern <shape> <diameter> "
                 "<yarn_thickness> <knot_type>\n";
    std::cerr << "For rectangle: crochet_pattern rectangle <length> <width> "
                 "<yarn_thickness> <knot_type>\n";
    std::cerr << "Shapes: circle, sphere, rectangle\n";
    std::cerr << "Knot type: 1=single crochet, 2=half double crochet\n";
    return 1;
  }

  std::string shape = argv[1];

  if (shape == "circle" || shape == "sphere") {
    if (argc < 5) {
      std::cerr << "Error: circle/sphere requires <diameter> <yarn_thickness> "
                   "<knot_type>\n";
      return 1;
    }
    double diameter = std::stod(argv[2]);
    double yarn_thickness = std::stod(argv[3]);
    int knot_type = std::stoi(argv[4]);

    if (shape == "circle") {
      pattern::Circle circle;
      if (knot_type == 1) {
        circle.single_crochet_dim(diameter, yarn_thickness);
      } else if (knot_type == 2) {
        circle.half_double_crochet_dim(diameter, yarn_thickness);
      } else {
        std::cerr << "Invalid knot type for circle.\n";
        return 1;
      }
    } else if (shape == "sphere") {
      pattern::Sphere sphere;
      if (knot_type == 1) {
        sphere.single_crochet_dim(diameter, yarn_thickness);
      } else if (knot_type == 2) {
        sphere.half_double_crochet_dim(diameter, yarn_thickness);
      } else {
        std::cerr << "Invalid knot type for sphere.\n";
        return 1;
      }
    }
  } else if (shape == "rectangle") {
    if (argc < 6) {
      std::cerr << "Error: rectangle requires <length> <width> "
                   "<yarn_thickness> <knot_type>\n";
      return 1;
    }
    double length = std::stod(argv[2]);
    double width = std::stod(argv[3]);
    double yarn_thickness = std::stod(argv[4]);
    int knot_type = std::stoi(argv[5]);

    pattern::Rectangle rectangle;
    if (knot_type == 1) {
      rectangle.single_crochet_dim(length, width, yarn_thickness);
    } else if (knot_type == 2) {
      rectangle.half_double_crochet_dim(length, width, yarn_thickness);
    } else {
      std::cerr << "Invalid knot type for rectangle.\n";
      return 1;
    }
  } else {
    std::cerr << "Invalid shape: " << shape << "\n";
    return 1;
  }

  return 0;
}