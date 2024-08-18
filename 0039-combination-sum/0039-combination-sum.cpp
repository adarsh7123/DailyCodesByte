
using vi = vector<int>;
using vvi = vector<vector<int>>;
using svi = set<vector<int>>;


class Solution {

private:

    void func(int ind, vi&arr, int target, vvi &ans, vi &ds){
        //base case
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }


        if(target>=arr[ind]){
            ds.push_back(arr[ind]);
            func(ind, arr, target-arr[ind], ans,ds);
            ds.pop_back();
        }

        func(ind+1,arr, target, ans, ds);
    }
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vvi ans;
        vi ds;
        func(0,candidates,target, ans, ds);
        return ans;
    }
};