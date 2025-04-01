#pragma once
#include <utility>

#include "stitch_count.h"

namespace pattern {
class Stitch {
 public:
  enum StitchType {
    kMr,
    kSc,
    kInc,
    kDec,
    kEor,
    kMulti
  };

  Stitch(StitchType stitch, int num_stitches);

  void set_stitch(StitchType stitch, int num_stitches);

  void set_stitch_type(StitchType stitch);

  void set_stitch_count(int num_stitches);

  std::pair<StitchType, int> get_stitch();

  Stitch::StitchType get_stitch_type();

  int get_stitch_count();

 private:
  std::pair<StitchType, StitchCount> stitch_;
};

}  // namespace pattern