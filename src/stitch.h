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

  Stitch(StitchType stitch, int num_stitches);

  void set_stitch(StitchType stitch, int num_stitches);

  void set_stitch_type(StitchType stitch);

  void set_stitch_count(int num_stitches);

  std::pair<StitchType, int> get_stitch();

  Stitch::StitchType get_stitch_type();

  int get_stitch_count();

 private:
  std::pair<StitchType, int> stitch_;
};

}  // namespace pattern