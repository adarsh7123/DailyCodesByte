class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total =0;
        int maxSum = nums[0];
        int curMax =0;
        int minSum = nums[0];
        int curMin = 0;
        for(auto &a:nums){
            curMax = max(curMax+a, a);
            maxSum = max(maxSum,curMax);
            curMin = min(curMin+a, a);
            minSum = min(minSum, curMin);
            total += a;
        }

        return maxSum > 0? max(maxSum, total- minSum):maxSum;


    }
};