#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
        
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int previ1 = 0;
        int previ2 = 0;
        
        for(int i=1; i<n; i++){
            int fs = previ1 + abs(height[i]-height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = previ2 + abs(height[i]-height[i-2]);
            }
            
            int curi = min(fs,ss);
            previ2 = previ1;
            previ1 = curi;
        }
        
        return previ1;
    }
};