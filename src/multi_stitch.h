#pragma once
#include <utility>

#include "simple_stitch.h"

namespace pattern {
class MultiStitch : public StitchCount {
 public:
  MultiStitch(int sc, int repeats) : num_sc_(sc), num_repeats_(repeats){};

  int get_num_sc() const {
    return num_sc_;
  }

  int get_num_repeats() const {
    return num_repeats_;
  }

 private:
  int num_sc_;
  int num_repeats_;
};

}  // namespace pattern