#include <bits/stdc++.h>
using namespace std;


void solve(vector<int> &height, int cost, int n, int &final)
{
    if (n == 0)
    {
        final = min(final, cost);
        return;
    }
    solve(height, cost + abs(height[n] - height[n - 1]), n - 1, final);
    if (n - 2 >= 0)
    {
        solve(height, cost + abs(height[n] - height[n - 2]), n - 2, final);
    }
    return;
}
int minCost(vector<int> &height)
{
    int cost = 0, final = INT_MAX;
    solve(height, cost, height.size() - 1, final);
    return final;
}