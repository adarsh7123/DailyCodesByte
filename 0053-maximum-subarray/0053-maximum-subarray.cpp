class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax =0, maxi = INT_MIN;

        for(auto c : nums){
            currMax = max(c, currMax+c);
            maxi = max(maxi,currMax);
        }

        return maxi;
    }
};