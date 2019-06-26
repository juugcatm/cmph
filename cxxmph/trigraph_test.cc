#include <cassert>

#include "gtest/gtest.h"

#include "trigraph.h"

using cxxmph::TriGraph;

TEST(TriGraph, integrationTest) {
  TriGraph g(4, 2);

  g.AddEdge(TriGraph::Edge(0, 1, 2));
  g.AddEdge(TriGraph::Edge(1, 3, 2));
  ASSERT_TRUE(g.vertex_degree()[0] == 1);
  ASSERT_TRUE(g.vertex_degree()[1] == 2);
  ASSERT_TRUE(g.vertex_degree()[2] == 2);
  ASSERT_TRUE(g.vertex_degree()[3] == 1);

  g.RemoveEdge(0);
  ASSERT_TRUE(g.vertex_degree()[0] == 0);
  ASSERT_TRUE(g.vertex_degree()[1] == 1);
  ASSERT_TRUE(g.vertex_degree()[2] == 1);
  ASSERT_TRUE(g.vertex_degree()[3] == 1);

  std::vector<TriGraph::Edge> edges;
  g.ExtractEdgesAndClear(&edges);
}
