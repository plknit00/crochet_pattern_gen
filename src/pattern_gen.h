#pragma once
#include "pattern.h"

// pattern is 2d vector with list of tuples with stich type and how many of
// those stich types, at end of list, it should have sum of stitches
// stich types: sc, inc, dec, eor (end of row)

namespace pattern {
class CrochetPattern {
 public:
  static void print_prompts();

  // convert inches to centimeters
  static float in_to_mm(float inches_val);

  static float cm_to_mm(float inches_val);

  static Row generate_magic_ring(int num_stitches);

  static Row generate_row(int num_stitches_begin, int num_stitches_end);

  static Pattern* create_pattern(int yarn_size, int shape, int diameter);

 private:
  float diameter_cm_;
  float yarn_size_cm_;
};
}  // namespace pattern