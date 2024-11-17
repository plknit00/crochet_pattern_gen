#pragma once

// pattern is 2d vector with list of tuples with stich type and how many of
// those stich types, at end of list, it should have sum of stitches
// stich types: sc, inc, dec, eor (end of row)

namespace pattern {
class CrochetPattern {
 public:
  // convert inches to centimeters
  float in_to_mm(float inches_val);

  float cm_to_mm(float inches_val);

  // Pattern* create_pattern();

 private:
  float diameter_cm_;
  float yarn_size_cm_;
};
}  // namespace pattern