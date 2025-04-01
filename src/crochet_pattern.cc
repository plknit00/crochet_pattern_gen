#include "crochet_pattern.h"

#include <iostream>
#include <sstream>
#include <string>

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
      rectangle_input();
      break;
    case 2:
      circle_input();
      break;
    case 3:
      sphere_input();
      break;
  }
}

void CrochetPattern::rectangle_input() {
  double length, width, yarn_thickness;
  std::cout << "Rectangle length in cm: ";
  std::cin >> length;
  std::cout << "Rectangle width in cm: ";
  std::cin >> width;
  std::cout << "Yarn thickness in cm: ";
  std::cin >> yarn_thickness;
  rectangle_dimensions(length, width, yarn_thickness);
}

void CrochetPattern::rectangle_dimensions(double length, double width,
                                          double yarn_thickness) {
  int single_crochet_knot_size = 2 * yarn_thickness;
  int num_stiches_per_row = width / (single_crochet_knot_size);
  int num_row = length / (single_crochet_knot_size);
  rectangle_crochet_pattern(num_stiches_per_row, num_row);
}

void CrochetPattern::rectangle_crochet_pattern(int num_stiches_per_row,
                                               int num_row) {
  for (int row = 0; row < num_row; row++) {
    std::cout << "Round " << row + 1 << ": (sc 1) x" << num_stiches_per_row
              << ", tc [" << num_stiches_per_row << "]" << std::endl;
  }
}

void CrochetPattern::circle_input() {
  double diameter, yarn_thickness;
  std::cout << "Circle diameter in cm: ";
  std::cin >> diameter;
  std::cout << "Yarn thickness in cm: ";
  std::cin >> yarn_thickness;
  circle_crochet_pattern(diameter, yarn_thickness);
}

void CrochetPattern::circle_crochet_pattern(double diameter,
                                            double yarn_thickness) {
  int single_crochet_knot_size = 2 * yarn_thickness;
  int num_rows = diameter / (2 * single_crochet_knot_size);
  circle_print(num_rows);
}

void CrochetPattern::circle_print(int num_rows) {
  int sc_mr = 6;
  for (int row = 0; row < num_rows; row++) {
    if (row == 0) {
      std::cout << "Round " << row + 1 << ": mr " << sc_mr << " [" << sc_mr
                << "]" << std::endl;
      continue;
    }
    if (row == 1) {
      std::cout << "Round " << row + 1 << ": inc x " << sc_mr << " ["
                << 2 * sc_mr << "]" << std::endl;
      continue;
    }
    int num_stiches = sc_mr * (row + 1);
    std::cout << "Round " << row + 1 << ": (sc " << (row - 1) << ", inc)x"
              << sc_mr << " [" << num_stiches << "]" << std::endl;
  }
}

void CrochetPattern::sphere_input() {
  double diameter, yarn_thickness;
  std::cout << "Sphere radius in cm: ";
  std::cin >> diameter;
  std::cout << "Yarn thickness in cm: ";
  std::cin >> yarn_thickness;
  sphere_crochet_pattern(diameter, yarn_thickness);
}

void CrochetPattern::sphere_crochet_pattern(double diameter,
                                            double yarn_thickness) {
  int single_crochet_knot_size = 2 * yarn_thickness;
  int num_rows = 3 * diameter / (2 * single_crochet_knot_size);
  sphere_print(num_rows);
}

void CrochetPattern::sphere_print(int num_rows) {
  std::cout << "Num rows " << num_rows << std::endl;
  int sc_mr = 6;
  for (int row = 0; row < num_rows; row++) {
    std::cout << "math= " << ((3 * (row + 1)) / num_rows) << std::endl;
    if (row == 0) {  // first row
      // std::cout << "FR" << std::endl;
      std::cout << "Round " << row + 1 << ": mr " << sc_mr << " [" << sc_mr
                << "]" << std::endl;
    } else if (row == 1) {  // second row
      // std::cout << "SR" << std::endl;
      std::cout << "Round " << row + 1 << ": inc x " << sc_mr << " ["
                << 2 * sc_mr << "]" << std::endl;
    } else if (row == num_rows - 1) {  // last row
      // std::cout << "LR" << std::endl;
      std::cout << "Round " << row + 1 << ": dec x " << sc_mr << " [" << sc_mr
                << "]" << std::endl;
    } else if (((3 * (row + 1)) / num_rows) <= 1) {  // beginning third
      // std::cout << "BT" << std::endl;
      int num_stiches = sc_mr * (row + 1);
      std::cout << "Round " << row + 1 << ": (sc " << (row - 1) << ", inc)x"
                << sc_mr << " [" << num_stiches << "]" << std::endl;
    } else if (((3 * (row + 1)) / num_rows) <= 2) {  // middle third
      // std::cout << "MT" << std::endl;
      int num_stiches = sc_mr * (row + 1);
      int num_rows_repeat = num_rows / 3;
      std::cout << "Rounds " << row + 1 << "-" << row + num_rows_repeat + 1
                << ": (" << num_rows_repeat << " rounds) sc around ["
                << num_stiches << "]" << std::endl;
      row += num_rows;
    } else {  // final third
      // std::cout << "FT " << std::endl;
      int num_stiches = sc_mr * (row + 1);
      std::cout << "Round " << row + 1 << ": (sc " << (num_rows - row)
                << ", dec)x" << sc_mr << " [" << num_stiches << "]"
                << std::endl;
    }
  }
}

}  // namespace pattern