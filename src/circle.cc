#include "circle.h"

#include <iostream>
#include <sstream>
#include <string>

namespace pattern {

void Circle::input() {
  double diameter, yarn_thickness;
  std::cout << "Circle diameter in cm: ";
  std::cin >> diameter;
  std::cout << "Yarn thickness in cm: ";
  std::cin >> yarn_thickness;
  knot_type(diameter, yarn_thickness);
}

void Circle::knot_type(double diameter, double yarn_thickness) {
  int knot_type;
  std::cout << "What knot type do you wish to use?" << std::endl;
  std::cout << "1. Single Crochet" << std::endl;
  std::cout << "2. Half Double Crochet" << std::endl;
  std::cin >> knot_type;
  if (knot_type == 1) {
    single_crochet_dim(diameter, yarn_thickness);
  } else if (knot_type == 2) {
    half_double_crochet_dim(diameter, yarn_thickness);
  }
}

void Circle::single_crochet_dim(double diameter, double yarn_thickness) {
  double num_rows = diameter / (2 * yarn_thickness);
  int num_rows_rounded = static_cast<int>(num_rows);
  single_crochet_print(num_rows_rounded);
}

void Circle::half_double_crochet_dim(double diameter, double yarn_thickness) {
  double half_double_crochet_knot_size = 2.25 * yarn_thickness;
  double num_rows = diameter / (2 * half_double_crochet_knot_size);
  int num_rows_rounded = static_cast<int>(num_rows);
  half_double_crochet_print(num_rows_rounded);
}

void Circle::single_crochet_print(int num_rows) {
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

void Circle::half_double_crochet_print(int num_rows) {
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
};  // namespace pattern