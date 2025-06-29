#pragma once

namespace pattern {
class Rectangle {
 public:
  // TO DO: check when things can be passed by reference
  // TO DO: turning chain math and pattern format

  static void pattern_gen(double length, double width, double yarn_thickness);

  static void single_crochet_dim(double length, double width,
                                 double yarn_thickness);

  static void half_double_crochet_dim(double length, double width,
                                      double yarn_thickness);

  static void single_crochet_pattern_print(int num_stiches_per_row,
                                           int num_row);

  static void half_double_crochet_pattern_print(int num_stiches_per_row,
                                                int num_row);
};
}  // namespace pattern