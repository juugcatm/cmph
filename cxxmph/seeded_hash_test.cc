#include "seeded_hash.h"

#include <unordered_map>
#include <string>
#include <iostream>

#include "gtest/gtest.h"

using namespace cxxmph;

TEST(SeededHash, integrationTest) {

  auto hasher = seeded_hash_function<Murmur3StringPiece>();
  std::string key1("0");
  std::string key2("1");
  auto h1 = hasher.hash128(key1, 1);
  auto h2 = hasher.hash128(key2, 1);
  ASSERT_TRUE(h1 != h2) << "Unexpected murmur collision";

  std::unordered_map<uint64_t, int> g;
  for (int i = 0; i < 1000; ++i) {
    g[i] = i;
  }

  for (int i = 0; i < 1000; ++i) {
    ASSERT_EQ(g[i], i);
  }

  auto inthasher = seeded_hash_function<std::hash<uint64_t>>();
  std::unordered_map<h128, uint64_t, h128::hash32> g2;
  for (uint64_t i = 0; i < 1000; ++i) {
    auto h = inthasher.hash128(i, 0);
    ASSERT_TRUE(g2.find(h) == g2.end()) << "Incorrectly found " << i;
    ASSERT_TRUE(h128::hash32()(h) == h[3]) << "Buggy hash method.";

    auto h2 = inthasher.hash128(i, 0);
    ASSERT_TRUE(h == h2)
      << "h 64(0) " << h.get64(0) << " h 64(1) " << h.get64(1) << "\n"
      << " h2 64(0) " << h2.get64(0) << " h2 64(1) " << h2.get64(1) << "\n"
      << "Broken equality for h128";

    ASSERT_TRUE(h128::hash32()(h) == h128::hash32()(h2))
      << "Inconsistent hash method.";

    g2[h] = i;
    ASSERT_TRUE(g2.find(h) != g2.end()) << "Incorrectly missed " << i;
  }
    
  for (uint64_t i = 0; i < 1000; ++i) {
    ASSERT_TRUE(g2[inthasher.hash128(i, 0)] == i);
  }
}
