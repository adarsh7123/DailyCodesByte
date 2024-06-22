class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        // intillize 1
        cnt[0] = 1;

        int ans = 0, t = 0;

        for (int v : nums) {
            t += v & 1; // check odd

            // if no. of t  is more than k it add in ans
            if (t - k >= 0) {
                ans += cnt[t - k];
            }

            // if it odd increase the t index count and add to cnt array
            //  if it even add ad same t index
            cnt[t]++;
        }

        return ans;
    }
};