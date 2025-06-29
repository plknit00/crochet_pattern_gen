#include "sphere.h"

#include <iostream>
#include <sstream>
#include <string>

namespace pattern {

void Sphere::pattern_gen(double diameter, double yarn_thickness) {
  int knot_type;
  std::cin >> knot_type;
  if (knot_type == 1) {
    single_crochet_dim(diameter, yarn_thickness);
  } else if (knot_type == 2) {
    half_double_crochet_dim(diameter, yarn_thickness);
  }
}

void Sphere::single_crochet_dim(double diameter, double yarn_thickness) {
  double num_rows = diameter / (2 * yarn_thickness);
  int num_rows_rounded = static_cast<int>(num_rows);
  single_crochet_print(num_rows_rounded);
}

void Sphere::half_double_crochet_dim(double diameter, double yarn_thickness) {
  double half_double_crochet_knot_size = 2.25 * yarn_thickness;
  double num_rows = 3 * diameter / half_double_crochet_knot_size;
  int num_rows_rounded = static_cast<int>(num_rows);
  half_double_crochet_print(num_rows_rounded);
}

void Sphere::single_crochet_print(int num_rows) {
  std::cout << "Num rows " << num_rows << std::endl;
  int sc_mr = 6;
  for (int row = 0; row < num_rows; row++) {
    if (row == 0) {  // first row
      std::cout << "Round " << row + 1 << ": mr " << sc_mr << " [" << sc_mr
                << "]" << std::endl;
    } else if (row == 1) {  // second row
      std::cout << "Round " << row + 1 << ": inc x " << sc_mr << " ["
                << 2 * sc_mr << "]" << std::endl;
    } else if (row == num_rows - 1) {  // last row
      std::cout << "Round " << row + 1 << ": dec x " << sc_mr << " [" << sc_mr
                << "]" << std::endl;
    } else if ((3 * ((row + 1) / static_cast<double>(num_rows))) <=
               1) {  // beginning third
      int num_stiches = sc_mr * (row + 1);
      std::cout << "Round " << row + 1 << ": (sc " << (row - 1) << ", inc)x"
                << sc_mr << " [" << num_stiches << "]" << std::endl;
    } else if ((3 * ((row + 1) / static_cast<double>(num_rows))) <=
               2) {  // middle third
      int num_stiches = sc_mr * row;
      int num_rows_repeat = num_rows / 3;
      std::cout << "Rounds " << row + 1 << "-" << row + num_rows_repeat << ": ("
                << num_rows_repeat << " rounds) sc around [" << num_stiches
                << "]" << std::endl;
      row += num_rows_repeat;
    } else {  // final third
      int num_stiches = sc_mr * (num_rows - row);
      std::cout << "Round " << row + 1 << ": (sc " << (num_rows - row)
                << ", dec)x" << sc_mr << " [" << num_stiches << "]"
                << std::endl;
    }
  }
}

void Sphere::half_double_crochet_print(int num_rows) {
  std::cout << "Num rows " << num_rows << std::endl;
  int sc_mr = 6;
  for (int row = 0; row < num_rows; row++) {
    if (row == 0) {  // first row
      std::cout << "Round " << row + 1 << ": mr " << sc_mr << " [" << sc_mr
                << "]" << std::endl;
    } else if (row == 1) {  // second row
      std::cout << "Round " << row + 1 << ": inc x " << sc_mr << " ["
                << 2 * sc_mr << "]" << std::endl;
    } else if (row == num_rows - 1) {  // last row
      std::cout << "Round " << row + 1 << ": dec x " << sc_mr << " [" << sc_mr
                << "]" << std::endl;
    } else if ((3 * ((row + 1) / static_cast<double>(num_rows))) <=
               1) {  // beginning third
      int num_stiches = sc_mr * (row + 1);
      std::cout << "Round " << row + 1 << ": (sc " << (row - 1) << ", inc)x"
                << sc_mr << " [" << num_stiches << "]" << std::endl;
    } else if ((3 * ((row + 1) / static_cast<double>(num_rows))) <=
               2) {  // middle third
      int num_stiches = sc_mr * row;
      int num_rows_repeat = num_rows / 3;
      std::cout << "Rounds " << row + 1 << "-" << row + num_rows_repeat << ": ("
                << num_rows_repeat << " rounds) sc around [" << num_stiches
                << "]" << std::endl;
      row += num_rows_repeat;
    } else {  // final third
      int num_stiches = sc_mr * (num_rows - row);
      std::cout << "Round " << row + 1 << ": (sc " << (num_rows - row)
                << ", dec)x" << sc_mr << " [" << num_stiches << "]"
                << std::endl;
    }
  }
}

};  // namespace pattern