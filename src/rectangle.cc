#include "rectangle.h"

#include <iostream>
#include <sstream>
#include <string>

namespace pattern {

void Rectangle::input() {
  double length, width, yarn_thickness;
  std::cout << "Rectangle length in cm: ";
  std::cin >> length;
  std::cout << "Rectangle width in cm: ";
  std::cin >> width;
  std::cout << "Yarn thickness in cm: ";
  std::cin >> yarn_thickness;
  knot_type(length, width, yarn_thickness);
}

void Rectangle::knot_type(double length, double width, double yarn_thickness) {
  int knot_type;
  std::cout << "What knot type do you wish to use?" << std::endl;
  std::cout << "1. Single Crochet" << std::endl;
  std::cout << "2. Half Double Crochet" << std::endl;
  std::cin >> knot_type;
  if (knot_type == 1) {
    single_crochet_dim(length, width, yarn_thickness);
  } else if (knot_type == 2) {
    half_double_crochet_dim(length, width, yarn_thickness);
  }
}

void Rectangle::single_crochet_dim(double length, double width,
                                   double yarn_thickness) {
  double num_stitches_per_row = width / yarn_thickness;
  int num_stitches_per_row_rounded = static_cast<int>(num_stitches_per_row);
  double num_row = length / yarn_thickness;
  int num_row_rounded = static_cast<int>(num_row);
  single_crochet_pattern_print(num_stitches_per_row_rounded, num_row_rounded);
}

void Rectangle::half_double_crochet_dim(double length, double width,
                                        double yarn_thickness) {
  double half_double_crochet_knot_width = 1.25 * yarn_thickness;
  double half_double_crochet_knot_length = 1.5 * yarn_thickness;
  double num_stitches_per_row = width / half_double_crochet_knot_width;
  int num_stitches_per_row_rounded = static_cast<int>(num_stitches_per_row);
  double num_row = length / half_double_crochet_knot_length;
  int num_row_rounded = static_cast<int>(num_row);
  half_double_crochet_pattern_print(num_stitches_per_row_rounded,
                                    num_row_rounded);
}

void Rectangle::single_crochet_pattern_print(int num_stiches_per_row,
                                             int num_row) {
  for (int row = 0; row < num_row; row++) {
    std::cout << "Round " << row + 1 << ": sc x" << num_stiches_per_row << " ["
              << num_stiches_per_row << "]" << std::endl;
  }
}

void Rectangle::half_double_crochet_pattern_print(int num_stiches_per_row,
                                                  int num_row) {
  for (int row = 0; row < num_row; row++) {
    std::cout << "Round " << row + 1 << ": sc x" << num_stiches_per_row
              << ", tc x2 [" << num_stiches_per_row << "]" << std::endl;
  }
}

};  // namespace pattern