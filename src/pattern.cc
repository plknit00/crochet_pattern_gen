#include "pattern.h"

#include <iostream>
#include <sstream>
#include <string>

#include "row.h"
#include "stitch.h"

namespace pattern {

void Pattern::print_stitch_pattern() {
  std::cout << to_string();
}

std::string Pattern::to_string() {
  std::stringstream ss;
  ss << "Circle Crochet Pattern" << std::endl;
  for (int row_index = 0; row_index < patt_.size(); row_index++) {
    Row row = patt_[row_index];
    ss << "Round " << row_index << ": ";
    for (int i = 0; i < patt_[row_index].size(); i++) {
      // use switch cases?
      Stitch st = row[i];
      Stitch::StitchType stitch_type = st.get_stitch_type();
      int stitch_count = st.get_stitch_count();
      switch (stitch_type) {
        case Stitch::StitchType::kMr:
          ss << "mr " << stitch_count << " ";
          break;
        case Stitch::StitchType::kSc:
          ss << "sc x" << stitch_count << " ";
          break;
        case Stitch::StitchType::kInc:
          ss << "inc x" << stitch_count << " ";
          break;
        case Stitch::StitchType::kDec:
          ss << "dec x" << stitch_count << " ";
          break;
        case Stitch::StitchType::kEor:
          ss << "[" << stitch_count << "]" << std::endl;
          break;
      }
    }
  }
  // if pattern is nullptr, it was tooo small, so print nothing
  return ss.str();
}

void Pattern::push_back(Row& row) {
  patt_.push_back(row);
}

}  // namespace pattern