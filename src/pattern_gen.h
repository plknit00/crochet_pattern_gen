#pragma once
#include "pattern.h"

// pattern is 2d vector with list of tuples with stich type and how many of
// those stich types, at end of list, it should have sum of stitches
// stich types: sc, inc, dec, eor (end of row)

namespace pattern {
class CrochetPattern {
 public:
  // convert inches to centimeters
  static float in_to_mm(float inches_val);

  static float cm_to_mm(float inches_val);

  static Pattern* generate_magic_circle(int num_stitches);

  static Pattern* generate_row(int num_stitches_begin, int num_stitches_end);

  std::vector<Pattern*> create_pattern(int diameter);

 private:
  float diameter_cm_;
  float yarn_size_cm_;
};
}  // namespace pattern