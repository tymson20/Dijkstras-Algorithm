#include <gtest/gtest.h>
#include "graphMatrix.h"

TEST(NodeTest, AssigningProperId) {
    Node n1, n2;
    EXPECT_EQ(n1.getId(), 1);
    EXPECT_EQ(n2.getId(), 2);
}

TEST(GraphMatrixTest, Constructor) {
    Node n1, n2;
    Matrix matrix = {{2, 0},
                     {0, 2}};
    std::vector<Node*> nodes = {&n1, &n2};
    GraphMatrix g1(nodes, matrix);
    ASSERT_EQ(g1.size(), 2);
    ASSERT_EQ(g1.getNodes(), nodes);
    ASSERT_EQ(g1.getMatrix(), matrix);
}

TEST(GraphMatrixTest, IsNodeBelong) {
    Node n1, n2;
    Matrix matrix = {{0}};
    std::vector<Node*> nodes = {&n1};
    GraphMatrix g1(nodes, matrix);
    ASSERT_TRUE(g1.isNodeBelong(&n1));
    ASSERT_FALSE(g1.isNodeBelong(&n2));
}

TEST(GraphMatrixTest, AddNode) {
    Node n1, n2, n3;
    std::vector<Node*> nodes = {&n1, &n2};
    Matrix matrix = {{0, 2},
                     {2, 0}};
    std::vector<Node*> correctNodes = {&n1, &n2, &n3};
    Matrix correctMatrix = {{0, 2, 0},
                            {2, 0, 0},
                            {0, 0, 0}};
    GraphMatrix g1(nodes, matrix);
    g1.addNode(&n3);
    ASSERT_EQ(g1.size(), 3);
    ASSERT_EQ(g1.getNodes(), correctNodes);
    ASSERT_EQ(g1.getMatrix(), correctMatrix);
}

TEST(GraphMatrixTest, GetEdge) {
    Node n1, n2, n3;
    std::vector<Node*> nodes = {&n1, &n2, &n3};
    Matrix matrix = {{0, 0, 3},
                     {0, 0, 1},
                     {3, 1, 0}};
    GraphMatrix g1(nodes, matrix);
    ASSERT_EQ(g1.getEdge(&n1, &n3), 3);
    ASSERT_EQ(g1.getEdge(&n3, &n1), 3);
    ASSERT_EQ(g1.getEdge(&n2, &n3), 1);
    ASSERT_EQ(g1.getEdge(&n2, &n1), 0);
}

TEST(GraphMatrixTest, AddEdge) {
    Node n1, n2, n3;
    std::vector<Node*> nodes = {&n1, &n2, &n3};
    Matrix matrix = {{0, 0, 3},
                     {0, 0, 1},
                     {3, 1, 0}};
    GraphMatrix g1(nodes, matrix);
    g1.addEdge(&n1, &n2, 5);
    ASSERT_EQ(g1.getEdge(&n1, &n2), 5);
    ASSERT_EQ(g1.getEdge(&n2, &n1), 5);
}

TEST(GraphMatrixTest, GetNeighbours) {
    Node n1, n2, n3, n4;
    std::vector<Node*> nodes = {&n1, &n2, &n3, &n4};
    Matrix matrix = {{0, 0, 3, 0},
                     {0, 0, 0, 0},
                     {3, 0, 0, 2},
                     {0, 0, 2, 0}};
    GraphMatrix g1(nodes, matrix);
    std::vector<Node*> result1 = {&n3};
    std::vector<Node*> result2;
    std::vector<Node*> result3 = {&n1, &n4};
    std::vector<Node*> result4 = {&n3};
    ASSERT_EQ(g1.getNeighbours(&n1), result1);
    ASSERT_EQ(g1.getNeighbours(&n2), result2);
    ASSERT_EQ(g1.getNeighbours(&n3), result3);
    ASSERT_EQ(g1.getNeighbours(&n4), result4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}