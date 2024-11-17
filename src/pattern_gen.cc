#include "pattern_gen.h"

#include "pattern.h"
#include "stitch.h"

namespace pattern {

float CrochetPattern::in_to_mm(float inches_val) {
  return inches_val * 25.4;
}

float CrochetPattern::cm_to_mm(float inches_val) {
  return inches_val * 10;
}

Pattern* CrochetPattern::generate_magic_circle(int num_stitches) {
  return nullptr;
}

Pattern* CrochetPattern::generate_row(int num_stitches_begin,
                                      int num_stitches_end) {
  return nullptr;
}

// later make this do different things for different shapes
// for now, just makes a circle
// assume each row is 0.5 mm
// later include yarn width in math
std::vector<Pattern*> CrochetPattern::create_pattern(int circle_diameter) {
  int num_rows = circle_diameter / 0.5;
  std::vector<Pattern*> pattern;
  for (int i = 0; i < num_rows; i++) {
    // magic circle
    if (i == 0) {
      // 6 is num_stitches in mc
      pattern[i] = generate_magic_circle(6);
    }
    // other rows
    else {
      // first input is the number of rows currently
      // second input is number of rows at end of row
      generate_row(i, 2 * i);
    }
  }
  return pattern;
}

}  // namespace pattern