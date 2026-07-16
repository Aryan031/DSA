#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int i2 = 0;
        int i1 = nums[0];
        int temp = 0;
        for (int i = 1; i < n; i++)
        {
            int notTake = i1;
            int take = nums[i];
            if (i > 1)
            {
                take = i2 + nums[i];
            }
            temp = max(take, notTake);
            i2 = i1;
            i1 = temp;
        }
        return i1;
    }
};