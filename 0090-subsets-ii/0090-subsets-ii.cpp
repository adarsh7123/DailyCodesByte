
using vi = vector<int>;
using vvi = vector<vector<int>>;
using svi = set<vector<int>>;


class Solution {
private:
    void func(vi& nums, int ind, vi&ds, svi& res){
       if (ind == nums.size()) {
            res.insert(ds);  // No need to sort here, set will handle uniqueness
            return;
        }

        // Include the current number
        ds.push_back(nums[ind]);
        func(nums, ind + 1, ds, res);

        // Exclude the current number
        ds.pop_back();
        func(nums, ind + 1, ds, res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vvi ans;
        svi res;
        vi ds;

       // Sort the input array to handle duplicates
        sort(nums.begin(), nums.end());

        // Call the recursive function
        func(nums, 0, ds, res);

        // Transfer results from set to vector
        for (auto& subset : res) {
            ans.push_back(subset);
        }

        return ans;
    }
};