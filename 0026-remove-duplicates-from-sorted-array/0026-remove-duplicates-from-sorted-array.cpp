class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //first element is always unique
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i]; //place unique element 
                j++;
            }
        }
        return j;
    }
};