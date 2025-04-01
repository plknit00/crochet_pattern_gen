#include "stitch.h"

namespace pattern {

Stitch::Stitch(StitchType stitch, int num_stitches)
    : stitch_(stitch, num_stitches){};

void Stitch::set_stitch(StitchType stitch, int num_stitches) {
  stitch_.first = stitch;
  stitch_.second = num_stitches;
}

void Stitch::set_stitch_type(StitchType stitch) {
  stitch_.first = stitch;
}

void Stitch::set_stitch_count(int num_stitches) {
  stitch_.second = num_stitches;
}

// fix return type?
std::pair<Stitch::StitchType, int> Stitch::get_stitch() {
  return stitch_;
}
_

    Stitch::StitchType
    Stitch::get_stitch_type() {
  return stitch_.first;
}

int Stitch::get_stitch_count() {
  return stitch_.second;
}

}  // namespace pattern