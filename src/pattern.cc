#include "pattern.h"

#include <iostream>
#include <string>

#include "row.h"
#include "stitch.h"

namespace pattern {

void Pattern::print_stitch_pattern() {
  for (int row_index = 0; row_index < patt_.size(); row_index++) {
    Row row = patt_[row_index];
    std::cout << "Round " << row_index << ": ";
    for (int i = 0; i < patt_[row_index].size(); i++) {
      // use switch cases?
      Stitch st = row[i];
      Stitch::StitchType stitch_type = st.get_stitch_type();
      int stitch_count = st.get_stitch_count();
      switch (stitch_type) {
        case Stitch::StitchType::kMr:
          std::cout << "mr " << stitch_count << " ";
          break;
        case Stitch::StitchType::kSc:
          std::cout << "sc " << stitch_count << " ";
          break;
        case Stitch::StitchType::kInc:
          std::cout << "inc " << stitch_count << " ";
          break;
        case Stitch::StitchType::kDec:
          std::cout << "dec " << stitch_count << " ";
          break;
        case Stitch::StitchType::kEor:
          std::cout << "[" << stitch_count << "]" << std::endl;
          break;
      }
    }
  }
  // if pattern is nullptr, it was tooo small, so print nothing
}

void Pattern::push_back(Row& row) {
  patt_.push_back(row);
}

}  // namespace pattern