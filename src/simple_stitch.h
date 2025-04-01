#pragma once
#include <utility>

#include "src/stitch_count.h"

namespace pattern {
class SimpleStitch : public StitchCount {
 public:
  int get_stitch_count() {
    return stitch_count_;
  }

 private:
  int stitch_count_;
};

}  // namespace pattern