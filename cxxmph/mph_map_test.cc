#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "mph_map.h"
#include "map_tester.h"
//#include "test.h"

using namespace cxxmph;

typedef MapTester<mph_map> Tester;

TEST(MphMap, EmptyFind) {
  ASSERT_TRUE(Tester::empty_find());
}

TEST(MphMap, EmptyErase) {
  ASSERT_TRUE(Tester::empty_erase());
}

TEST(MphMap, SmallInsert) {
  ASSERT_TRUE(Tester::small_insert());
}

TEST(MphMap, LargeInsert) {
  ASSERT_TRUE(Tester::large_insert());
}

TEST(MphMap, SmallSearch) {
  ASSERT_TRUE(Tester::small_search());
}

TEST(MphMap, DefaultSearch) {
  ASSERT_TRUE(Tester::default_search());
}

TEST(MphMap, LargeSearch) {
  ASSERT_TRUE(Tester::large_search());
}

TEST(MphMap, StringSearch) {
  ASSERT_TRUE(Tester::string_search());
}

TEST(MphMap, RehashZero) {
  ASSERT_TRUE(Tester::rehash_zero());
}

TEST(MphMap, RehashSize) {
  ASSERT_TRUE(Tester::rehash_size());
}

TEST(MphMap, EraseValue) {
  ASSERT_TRUE(Tester::erase_value());
}

TEST(MphMap, EraseIterator) {
  ASSERT_TRUE(Tester::erase_iterator());
}
