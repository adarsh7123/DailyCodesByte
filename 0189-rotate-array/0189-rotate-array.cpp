class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> b;
        for (int i = n - k; i < n; i++)
            b.push_back(nums[i]);
        for (int i = 0; i < n - k; i++)
            b.push_back(nums[i]);
        for (int i = 0; i < n; i++)
            nums[i] = b[i];
    }
};