#include "src/pattern_gen.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace pattern {

using StitchType = Stitch::StitchType;

TEST(PatternTest, Basic) {
  ASSERT_EQ(CrochetPattern::create(CrochetPattern::Shape::kCircle, 5, 10)
                ->to_string(),
            R"(Circle Crochet Pattern
Round 0: mr 6 [6]
Round 1: inc x6 [12]
Round 2: inc x12 [24]
Round 3: inc x24 [48]
)");
}

TEST(PatternTest, BigCircle) {
  ASSERT_EQ(CrochetPattern::create(CrochetPattern::Shape::kCircle, 4, 48)
                ->to_string(),
            R"(Circle Crochet Pattern
Round 0: mr 6 [6]
Round 1: inc x6 [12]
Round 2: inc x12 [24]
Round 3: inc x24 [48]
)");
}

}  // namespace pattern
