#pragma once

#include "stitch.h"
#include <utility>
#include <vector>

namespace pattern {
class Pattern {
public:
  // sums up the amount of each type of stitch to give the end of row total
  // stitch count after completing that row
  void get_eor_count();

private:
  std::vector<std::pair<Stitch::StitchType, int>> row;
};

} // namespace pattern