#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

#include "hollow_iterator.h"
using cxxmph::hollow_iterator_base;
using cxxmph::make_hollow;
using cxxmph::is_empty;

TEST(HollowIteratorTest, integrationTest) {
  std::vector<int> v;
  std::vector<bool> p;
  for (int i = 0; i < 100; ++i) {
    v.push_back(i);
    p.push_back(i % 2 == 0);
  }

  auto begin = make_hollow(&v, &p, v.begin());
  auto end = make_hollow(&v, &p, v.end());
  for (auto it = begin; it != end; ++it) {
    ASSERT_TRUE(((*it) % 2) == 0);
  }

  const std::vector<int>* cv(&v);
  auto cbegin(make_hollow(cv, &p, cv->begin()));
  auto cend(make_hollow(cv, &p, cv->begin()));
  for (auto it = cbegin; it != cend; ++it) {
    ASSERT_TRUE(((*it) % 2) == 0);
  }

  const std::vector<bool>* cp(&p);
  cbegin = make_hollow(cv, cp, v.begin());
  cend = make_hollow(cv, cp, cv->end());

  std::vector<int>::iterator vit1 = v.begin();
  std::vector<int>::const_iterator vit2 = v.begin();
  ASSERT_TRUE(vit1 == vit2);

  auto it1 = make_hollow(&v, &p, vit1);
  auto it2 = make_hollow(&v, &p, vit2);
  ASSERT_TRUE(it1 == it2);

  typedef is_empty<const std::vector<int>> iev;
  hollow_iterator_base<std::vector<int>::iterator, iev> default_constructed;
  default_constructed = make_hollow(&v, &p, v.begin());
}

