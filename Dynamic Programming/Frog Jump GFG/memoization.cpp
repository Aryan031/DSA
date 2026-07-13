#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int solve(vector<int>& height, int n, vector<int>& dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int first = solve(height, n-1, dp)+ abs(height[n]-height[n-1]);
        int second = INT_MAX;
        if(n-2>=0){
            second = solve(height, n-2, dp) + abs(height[n]-height[n-2]);
        }
        dp[n] = min(first,second);
        return dp[n];
    }
        
    int minCost(vector<int>& height) {
        // Code here
        int cost=0, final = INT_MAX;
        vector<int> dp(height.size()+1,-1);
        
        return solve(height,height.size()-1,dp);;
    }
};