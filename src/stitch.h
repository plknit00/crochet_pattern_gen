#pragma once
#include <utility>

namespace pattern {
class Stitch {
 public:
  enum StitchType {
    kMr,
    kSc,
    kInc,
    kDec,
    kEor
  };

  void set_stitch(StitchType stitch, int num_stitches);

  std::pair<StitchType, int> get_stitch();

 private:
  std::pair<StitchType, int> stitch_;
};

}  // namespace pattern