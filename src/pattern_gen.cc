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

// Pattern* CrochetPattern::create_pattern() {}

}  // namespace pattern