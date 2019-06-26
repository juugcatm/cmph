#include "string_util.h"

#include "gtest/gtest.h"

using namespace cxxmph;

TEST(StringUtil, testFormat) {
  string expected = " %% 4 foo 0x0A bar ";
  string foo = "foo";
  string fmt = format(" %%%% %v %v 0x%.2X bar ", 4, foo, 10);
  ASSERT_TRUE(fmt == expected);
}

TEST(StringUtil, infoln) {
  infoln(string("%s:%d: MY INFO LINE"), __FILE__, __LINE__);
}


TEST(StringUtil, macro) {
  CXXMPH_DEBUGLN("here i am")();
}
