#pragma once
#include <vector>

#include "stitch.h"

namespace pattern {
class Row {
 public:
  void set_row(Stitch::StitchType stitch, int num_stitches, int index);

  std::vector<Stitch> get_row();

 private:
  std::vector<Stitch> row_;
};

}  // namespace pattern