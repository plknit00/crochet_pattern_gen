#pragma once
#include <vector>

#include "stitch.h"

namespace pattern {
class Row {
 public:
  void set_row(Stitch::StitchType stitch, int num_stitches);

  std::vector<Stitch> get_row();

  int size();

  Stitch& operator[](int index);

  // sums up the amount of each type of stitch to give the end of row total
  // stitch count after completing that row
  void set_eor_count();

  void push_back(Stitch stitch);

 private:
  std::vector<Stitch> row_;
};

}  // namespace pattern