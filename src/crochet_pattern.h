#pragma once

namespace pattern {
class CrochetPattern {
 public:
  //   enum class Shape {
  //     kRectangle,
  //     kCircle,
  //     kSphere
  //   };

  // TO DO: do input checks and say when patterns aren't possible/too small
  // TO DO: later add parameter to request different stitch types
  static void decide_shape();

  static void rectangle_input();

  static void rectangle_dimensions(double length, double width,
                                   double yarn_thickness);

  static void rectangle_crochet_pattern(int num_stiches_per_row, int num_row);

  static void circle_input();

  static void circle_crochet_pattern(double diameter, double yarn_thickness);

  static void circle_print(int num_rows);

  static void sphere_input();

  static void sphere_crochet_pattern(double diameter, double yarn_thickness);

  static void sphere_print(int num_rows);

  //  private:
  //   float diameter_cm_;
  //   float yarn_size_cm_;
};
}  // namespace pattern