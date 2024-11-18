#include "row.h"

#include "stitch.h"

namespace pattern {
void Row::set_row(Stitch::StitchType stitch, int num_stitches, int index) {
  row_[index].set_stitch(stitch, num_stitches);
}

std::vector<Stitch> Row::get_row() {
  return row_;
}

}  // namespace pattern