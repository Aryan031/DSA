#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return nums[0];
        }
        if (n < 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int take = nums[n] + solve(nums, n - 2, dp);
        int notTake = solve(nums, n - 1, dp);
        return dp[n] = max(take, notTake);
    }

    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(nums, nums.size() - 1, dp);
    }
};