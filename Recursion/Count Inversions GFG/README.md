# Count Inversions in an Array

## Problem URL 
- https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

# Approach - Brute Force
- This problem wants us to find any iversion in array for which there are two indices i and j where i<j and arr[i]>arr[j]
- To tackle this problem, we can either take brute force approach where we can check for each element, how many elements in its right are smaller than current element. But this will take O(n^2) and its the brute force approach

# Approach - Optimized
- As in Merge Sort, what we do is we have 2 arrays which are sorted. Now we compare values in these arrays one by one and merge them
- While comparing, we can check if left element is greater than right element. If it is true, we can increment our counter.
- Eg: leftArr=[1,2,3] and rightArr=[1,1]. Now in the second comparison with element 2, we can see that left is greater than right element (2>1)
- This means all elements in leftArr after 2 will also be greater than element in rightArr (because leftArr is sorted)
- So, count += size(leftArr)-indexOf(2)
