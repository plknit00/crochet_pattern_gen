#include "pattern.h"
#include "stitch.h"

namespace pattern {

void Pattern::get_eor_count() {
  int total_stitch_count = 0;
  for (int i = 0; i < row.size() - 1; i++) {
    std::pair<Stitch::StitchType, int> stitch = row[i];
    // single crochet, decrease stitch, magic ring
    if ((stitch.first == 2) || (stitch.first == 3) || (stitch.first == 1)) {
      total_stitch_count += stitch.second;
    }
    // increase stitch
    else if (stitch.first == 2) {
      total_stitch_count += stitch.second * 2;
    }
  }
  // setting end of row count
  row[row.size() - 1].second = total_stitch_count;
}

} // namespace pattern