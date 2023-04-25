#include <cstdlib>
#include <iostream>
#include <new>
// Ignore error below for #include <gtest/gtest.h>
#include <gtest/gtest.h>
using std::vector;
using std::string;

extern "C" {
  #include "linked_list.h"
}

// Keep this for a little bit to refer back to
TEST(suiteName, testName) {
  ASSERT_EQ(1,1);
}

TEST(linked_list, linked_list_create) {
  linked_list_t* list;
  list = linked_list_create();
  ASSERT_NE(list, nullptr);
}

TEST(linked_list, linked_list_destroy_null) {
  int return_val = linked_list_destroy(NULL);
  ASSERT_EQ(return_val, -1);
}

TEST(linked_list, linked_list_destroy_good) {
  linked_list_t* list;
  list = linked_list_create();
  ASSERT_NE(list, nullptr);
  linked_list_destroy(&list);
  ASSERT_EQ(list, nullptr);
}

TEST(linked_list, linked_list_add_null_list) {
  node_t* node = node_create();
  ASSERT_NE(node, nullptr);
  int return_value = linked_list_add(NULL, node);
  ASSERT_EQ(return_value, -1);
}

TEST(linked_list, linked_list_add_null_node) {
  linked_list_t* list = linked_list_create();
  ASSERT_NE(list, nullptr);
  int return_value = linked_list_add(list, NULL);
  ASSERT_EQ(return_value, -1);
}

TEST(linked_list, linked_list_add_good) {
  linked_list_t* list = linked_list_create();
  ASSERT_NE(list, nullptr);
  int test_value = 10;
  node_t* node = node_create();
  node_set_data(node, &test_value);
  ASSERT_EQ(10, *(int*)node->data);
  linked_list_add(list, node);
  ASSERT_EQ(list->size, 1);
}

TEST(linked_list, linked_list_add_index_null) {
  // get everything set up
  linked_list_t* list = linked_list_create();
  ASSERT_NE(list, nullptr);

  node_t* node = node_create();
  ASSERT_NE(node, nullptr);
  int test_val = 10;
  node_set_data(node, &test_val);

  int index = 0;

  // test null list
  int return_value = linked_list_add_index(NULL, node, index);
  ASSERT_EQ(return_value, -1);

  // test null node
  return_value = linked_list_add_index(list, NULL, index);
  ASSERT_EQ(return_value, -1);

  // test bad index
  return_value = linked_list_add_index(list, node, 100);
  ASSERT_EQ(return_value, -1);
}

TEST(linked_list, linked_list_add_index_good) {
  linked_list_t* list = linked_list_create();
  ASSERT_NE(list, nullptr);

  node_t* node = node_create();
  ASSERT_NE(node, nullptr);
  int test_val = 10;
  node_set_data(node, &test_val);

  int index = 0;
  linked_list_add_index(list, node, index);
  ASSERT_EQ(list->size, 1);
}

TEST(linked_list, linked_list_add_index_index_too_large) {
  linked_list_t* list = linked_list_create();
  ASSERT_NE(list, nullptr);

  node_t* node = node_create();
  ASSERT_NE(node, nullptr);
  int test_val = 10;
  node_set_data(node, &test_val);

  int index = 100;
  ASSERT_EQ(linked_list_add_index(list, node, index), -1);
  ASSERT_EQ(list->size, 0);
}

TEST(linked_list, linked_list_add_index_index_too_small) {
  linked_list_t* list = linked_list_create();
  ASSERT_NE(list, nullptr);

  node_t* node = node_create();
  ASSERT_NE(node, nullptr);
  int test_val = 10;
  node_set_data(node, &test_val);

  int index = -100;
  ASSERT_EQ(linked_list_add_index(list, node, index), -1);
  ASSERT_EQ(list->size, 0);
}



int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}