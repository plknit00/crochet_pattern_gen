#pragma once

#include <utility>
#include <vector>

#include "stitch.h"

namespace pattern {
class Pattern {
 public:
  void print_prompts();

  // sums up the amount of each type of stitch to give the end of row total
  // stitch count after completing that row
  void get_eor_count();

  void print_stitch_pattern();

 private:
  std::vector<std::pair<Stitch::StitchType, int> > row_;
};

}  // namespace pattern