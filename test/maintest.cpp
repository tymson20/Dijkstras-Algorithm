#include <gtest/gtest.h>
#include "graph.h"

TEST(NodeTest, AssigningProperId) {
    Node n1, n2;
    EXPECT_EQ(n1.getId(), 1);
    EXPECT_EQ(n2.getId(), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}