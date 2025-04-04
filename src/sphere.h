#pragma once

namespace pattern {
class Sphere {
 public:
  // TO DO: check when things can be passed by reference
  // TO DO: HDC

  static void input();

  static void knot_type(double diameter, double yarn_thickness);

  static void single_crochet_dim(double diameter, double yarn_thickness);

  static void half_double_crochet_dim(double diameter, double yarn_thickness);

  static void single_crochet_print(int num_rows);

  static void half_double_crochet_print(int num_rows);
};
}  // namespace pattern