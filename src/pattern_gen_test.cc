// #include "src/pattern_gen.h"

// #include "gmock/gmock.h"
// #include "gtest/gtest.h"

// namespace pattern {

// using StitchType = Stitch::StitchType;

// TEST(PatternTest, Basic) {
//   ASSERT_EQ(CrochetPattern::create(CrochetPattern::Shape::kCircle, 5, 10)
//                 ->to_string(),
//             R"(Circle Crochet Pattern
// Round 0: mr 6 [6]
// Round 1: inc x12 [12]
// Round 2: (sc 1,inc)x6 [18]
// Round 3: (sc 2,inc)x6 [24]
// )");
// }

// TEST(PatternTest, BigCircle) {
//   ASSERT_EQ(CrochetPattern::create(CrochetPattern::Shape::kCircle, 4, 48)
//                 ->to_string(),
//             R"(Circle Crochet Pattern
// Round 0: mr 6 [6]
// Round 1: inc x12 [12]
// Round 2: (sc 1,inc)x6 [18]
// Round 3: (sc 2,inc)x6 [24]
// Round 4: (sc 3,inc)x6 [30]
// Round 5: (sc 4,inc)x6 [36]
// Round 6: (sc 5,inc)x6 [42]
// )");
// }

// }  // namespace pattern