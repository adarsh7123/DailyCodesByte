
using vi = vector<int>;
using vvi = vector<vector<int>>;
using svi = set<vector<int>>;

class Solution {

private:
void func(int ind, int target, vi& arr, vvi&ans, vi&ds){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i = ind; i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target)break;
        ds.push_back(arr[i]);
        func(i+1,target-arr[i],arr, ans, ds);
        ds.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vvi ans;
        vi ds;
        sort(candidates.begin(), candidates.end());
        func(0,target, candidates, ans, ds);
        return ans;

    }
};