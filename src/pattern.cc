#include "pattern.h"

#include <iostream>
#include <string>

#include "stitch.h"

namespace pattern {

void print_prompts() {
  int yarn_size;
  std::string shape;
  std::cout << "Which size yarn are you using in mm?" << std::endl;
  // add more units options
  std::cin >> yarn_size;
  std::cout << "Which shape do you want to make?" << std::endl;
  std::cout << "1. Circle" << std::endl;
  // error check for valid input
  // make prompts specific for each shape
  std::cout << "What size diameter do you want in mm?" << std::endl;
}

void Pattern::get_eor_count() {
  int total_stitch_count = 0;
  for (int i = 0; i < row_.size() - 1; i++) {
    std::pair<Stitch::StitchType, int> stitch = row_[i];
    // single crochet, decrease stitch, magic ring
    if ((stitch.first == 2) || (stitch.first == 3) || (stitch.first == 1)) {
      total_stitch_count += stitch.second;
    }
    // increase stitch
    else if (stitch.first == 2) {
      total_stitch_count += stitch.second * 2;
    }
  }
  // setting end of row count
  row_[row_.size() - 1].second = total_stitch_count;
}

void Pattern::print_stitch_pattern() {
  for (auto& i : row_) {
    // use switch cases?
    // if (row_[i].first == Stitch::MR) {
    //   std::cout << " " << std::endl;
    // } else if (row_[i].first == Stitch::SC) {
    //   std::cout << " " << std::endl;
    // } else if (row_[i].first == Stitch::INC) {
    //   std::cout << " " << std::endl;
    // } else if (row_[i].first == Stitch::DEC) {
    //   std::cout << " " << std::endl;
    // }
    // // end of row
    // else {
    //   std::cout << " " << std::endl;
    // }
    std::cout << i.first << i.second << " ";
  }
  std::cout << std::endl;
}

}  // namespace pattern