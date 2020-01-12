#include "headers.h"

class Solution
{
  public:
    int climbStairs(int n)
    {
        int ways[] = {1, 1};
        for (int i = 1; i < n; i++)
        {
            int temp = ways[1];
            ways[1] += ways[0];
            ways[0] = temp;
        }
        return ways[1];
    }
};

TEST(climbStairs, climbStairs)
{
    Solution s;
    EXPECT_EQ(s.climbStairs(2), 2);
    EXPECT_EQ(s.climbStairs(3), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}