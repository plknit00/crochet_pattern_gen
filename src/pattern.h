#pragma once

#include <utility>
#include <vector>

#include "row.h"
#include "stitch.h"

namespace pattern {
class Pattern {
 public:
  void print_stitch_pattern();

  std::string to_string();

  void push_back(Row& row);

 private:
  std::vector<Row> patt_;
};

}  // namespace pattern