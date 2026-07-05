#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void merge(vector<int>& arr, int low, int mid, int high, int& count){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                count += mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
        return;
    }
  
    void mergeSort(vector<int>& arr, int low, int high, int& count){
        if(low>=high){
            return;
        }
        int mid = (low+high)/2;
        mergeSort(arr,low,mid,count);
        mergeSort(arr,mid+1,high,count);
        merge(arr,low,mid,high,count);
    }
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        int count=0;
        mergeSort(arr,0,arr.size()-1,count);
        return count;
    }
};