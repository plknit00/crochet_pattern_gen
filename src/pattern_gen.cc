#include "pattern_gen.h"

#include <iostream>
#include <string>

#include "pattern.h"
#include "stitch.h"

namespace pattern {

void CrochetPattern::print_prompts() {
  // error check for valid input from cin
  int yarn_size, shape, diameter;
  std::cout << "Which size yarn are you using in mm?" << std::endl;
  // add more units options
  std::cin >> yarn_size;
  std::cout << "Which shape do you want to make?" << std::endl;
  std::cout << "1. Circle" << std::endl;
  std::cin >> shape;
  // make functions for shape specific prompts after this
  std::cout << "What size diameter do you want in mm?" << std::endl;
  std::cin >> diameter;
  // do stuff with the ints based upon cin results
  Pattern* pat = create_pattern(yarn_size, shape, diameter);
  pat->Pattern::print_stitch_pattern();
}

float CrochetPattern::in_to_mm(float inches_val) {
  return inches_val * 25.4;
}

float CrochetPattern::cm_to_mm(float inches_val) {
  return inches_val * 10;
}

Row CrochetPattern::generate_magic_ring(int num_stitches) {
  Row row;
  row.set_row(Stitch::StitchType::kMr, num_stitches);
  row.set_eor_count();
  return row;
}

Row CrochetPattern::generate_row(int num_stitches_begin, int num_stitches_end) {
  // for now: begin * 2 = end
  Row row;
  row.set_row(Stitch::StitchType::kInc, num_stitches_begin);
  // do EOR stuff, use set_eor_count in row.h
  row.set_eor_count();
  return row;
}

// later make this do different things for different shapes
// for now, just makes a circle
// assume each row is 5 mm in width, thus yarn size must be >= 5mm
// later include yarn width in math
Pattern* CrochetPattern::create_pattern(int yarn_size, int shape,
                                        int diameter) {
  // int. div. rounds down, this part will use estimation/grouping
  int num_rows = diameter / 5;
  std::cout << "Number of rows " << num_rows << std::endl;
  // ensure that diam and yarn size are same unit
  Pattern* pat = new Pattern();
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
      i = 6 * i;
      Row row = generate_row(i, 2 * i);
      pat->push_back(row);
    }
  }
  return pat;
}

}  // namespace pattern