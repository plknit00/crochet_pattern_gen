#include "crochet_pattern.h"

#include <iostream>
#include <sstream>
#include <string>

#include "circle.h"
#include "rectangle.h"
#include "sphere.h"

namespace pattern {

void CrochetPattern::decide_shape() {
  int shape;
  std::cout << "Project shape, please select a number:" << std::endl;
  std::cout << "1. Rectangle" << std::endl;
  std::cout << "2. Circle" << std::endl;
  std::cout << "3. Sphere" << std::endl;
  std::cout << "Selection: ";
  std::cin >> shape;
  switch (shape) {
    case 1:
      Rectangle::input();
      break;
    case 2:
      Circle::input();
      break;
    case 3:
      Sphere::input();
      break;
  }
}

}  // namespace pattern