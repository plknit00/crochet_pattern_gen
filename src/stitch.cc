#include "stitch.h"

namespace pattern {

void Stitch::set_stitch(StitchType stitch, int num_stitches) {
  stitch_.first = stitch;
  stitch_.second = num_stitches;
}

std::pair<Stitch::StitchType, int> Stitch::get_stitch() {
  return stitch_;
}

}  // namespace pattern