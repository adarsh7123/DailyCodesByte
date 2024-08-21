#include <bits/stdc++.h>
class Solution {
public:
 
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>min_heap(nums.begin(), nums.begin() + k);
        
       for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};