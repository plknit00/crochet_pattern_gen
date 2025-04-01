#include "pattern_gen.h"

#include <iostream>
#include <string>

#include "pattern.h"
#include "stitch.h"

namespace pattern {

void CrochetPattern2::print_prompts() {
  // error check for valid input from cin
  int yarn_width, shape, obj_diameter;
  std::cout << "Which size yarn are you using in mm?" << std::endl;
  // add more units options
  std::cin >> yarn_width;
  std::cout << "Which shape do you want to make?" << std::endl;
  std::cout << "1. Circle" << std::endl;
  std::cout << "2. Sphere" << std::endl;
  std::cin >> shape;
  // make functions for shape specific prompts after this
  std::cout << "What size diameter do you want in cm?" << std::endl;
  std::cin >> obj_diameter;
  // do stuff with the ints based upon cin results
  Pattern* pat;
  if (shape == 1) {
    pat = create_pattern_circle(yarn_width, obj_diameter);
  } else {
    pat = create_pattern_sphere(yarn_width, obj_diameter);
  }
  pat->Pattern::print_stitch_pattern();
}

Pattern* CrochetPattern2::create(CrochetPattern::Shape shape, int yarn_width,
                                 int obj_diameter) {
  switch (shape) {
    case Shape::kCircle:
      return create_pattern_circle(yarn_width, obj_diameter);
    case Shape::kSphere:
      return create_pattern_sphere(yarn_width, obj_diameter);
  }
}

float CrochetPattern2::in_to_mm(float inches_val) {
  return inches_val * 25.4;
}

float CrochetPattern2::cm_to_mm(float inches_val) {
  return inches_val * 10;
}

Row CrochetPattern2::generate_magic_ring(int num_stitches) {
  Row row;
  row.set_row(Stitch::StitchType::kMr, num_stitches);
  row.set_eor_count();
  return row;
}

Row CrochetPattern2::generate_row_circle(int num_stitches_begin) {
  int num_stitches_end = num_stitches_begin + 6;
  // float factor_of_increase = num_stitches_end / num_stitches_begin;
  int num_single_crochet = num_stitches_begin / 6 - 1;
  Row row;
  if (num_single_crochet == 0) {
    row.set_row(Stitch::StitchType::kInc, num_stitches_begin);
  } else {
    int num_repeats = num_stitches_end / (num_single_crochet + 2);
    row.sc_inc_repeat_stitch_row(num_single_crochet, num_repeats);
  }
  // do EOR stuff, use set_eor_count in row.h
  row.set_eor_count();
  return row;
}

Pattern* CrochetPattern2::create_pattern_circle(int yarn_width,
                                                int obj_diameter) {
  // int. div. rounds down, this part will use estimation/grouping
  // ensure this math is reasonable to how big stitches are
  int num_rows = (obj_diameter * 2) / yarn_width;
  std::cout << "Num rows: " << num_rows << std::endl;
  // ensure that diam and yarn size are same unit
  auto* pat = new Pattern();
  if (num_rows == 0) {
    std::cout << "This pattern is too small." << std::endl;
    return pat;
  }
  for (int i = 0; i < num_rows; i++) {
    // magic ring
    if (i == 0) {
      // 6 is num_stitches in mr
      Row row = generate_magic_ring(6);
      pat->push_back(row);
    }
    // other rows
    else {
      // first input is the number of rows currently
      // second input is number of rows at end of row
      int index = 6 * (i + 1);
      std::cout << "index: " << index << std::endl;
      Row row = generate_row_circle(index);
      pat->push_back(row);
    }
  }
  return pat;
}

Pattern* CrochetPattern2::create_pattern_sphere(int yarn_width,
                                                int obj_diameter) {
  return nullptr;
}

}  // namespace pattern