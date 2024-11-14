#pragma once
#include <utility>

namespace pattern {
class Stitch {
public:
  enum StitchType { MR, SC, INC, DEC, EOR };

private:
  std::pair<StitchType, int> stitch;
};

} // namespace pattern