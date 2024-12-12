#include "row.h"

#include <iostream>
#include <ostream>

#include "stitch.h"

namespace pattern {
void Row::set_row(Stitch::StitchType stitch, int num_stitches) {
  Stitch st(stitch, num_stitches);
  row_.push_back(st);
}

std::vector<Stitch> Row::get_row() {
  return row_;
}

int Row::size() {
  return row_.size();
}

// Overload the [] operator
Stitch& Row::operator[](int index) {
  return row_[index];
}

void Row::set_eor_count() {
  int total_stitch_count = 0;
  for (auto& i : row_) {
    // total_stitch_count += i.get_stitch_count();
    Stitch::StitchType stitch_type = i.get_stitch_type();
    // single crochet, decrease stitch, magic ring
    if ((stitch_type == Stitch::StitchType::kSc) ||
        (stitch_type == Stitch::StitchType::kDec) ||
        (stitch_type == Stitch::StitchType::kMr)) {
      total_stitch_count += i.get_stitch_count();
    }
    // increase stitch
    else if (stitch_type == Stitch::StitchType::kInc) {
      total_stitch_count += 2 * i.get_stitch_count();
    }
  }
  Stitch st(Stitch::StitchType::kEor, total_stitch_count);
  row_.push_back(st);
}

void Row::push_back(Stitch stitch) {
  row_.push_back(stitch);
}

}  // namespace pattern