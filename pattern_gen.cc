#include "pattern_gen.h"
#include "pattern.h"
#include "stitch.h"

namespace pattern {

class CrochetPattern {
public:
  // convert inches to centimeters
  float in_to_cm(float inches_val) { return inches_val * 2.54; }

  // Pattern* create_pattern() {}

private:
  float diameter_cm_;
  float yarn_size_cm_;
};

} // namespace pattern