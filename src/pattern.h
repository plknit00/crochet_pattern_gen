#pragma once

#include <utility>
#include <vector>

#include "row.h"
#include "stitch.h"

namespace pattern {
class Pattern {
 public:
  static void print_prompts();

  // sums up the amount of each type of stitch to give the end of row total
  // stitch count after completing that row
  void set_eor_count();

  void print_stitch_pattern();

 private:
  std::vector<Row*> patt_;
};

}  // namespace pattern