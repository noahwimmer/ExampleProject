#include <cstdlib>
#include <iostream>
#include <new>
#include <gtest/gtest.h>
using std::vector;
using std::string;

extern "C" {
  #include "linked_list.h"
}


class Environment : public testing::Environment {
  
};

TEST(suiteName, testName) {
  ASSERT_EQ(1,1);
  
  
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}