class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int element;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                element = nums[i];
                count++;
            }

           else if (element == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return element;
    }
};