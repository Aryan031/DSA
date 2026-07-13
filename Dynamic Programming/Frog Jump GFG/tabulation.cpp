#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
        
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n,-1);
        
        dp[0]=0;
        
        for(int i=1; i<n; i++){
            int fs = dp[i-1] + abs(height[i]-height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = dp[i-2] + abs(height[i]-height[i-2]);
            }
            dp[i] = min(fs,ss);
        }
        
        return dp[n-1];
    }
};