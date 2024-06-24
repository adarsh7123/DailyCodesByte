class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, k = INT_MAX;
        for (auto& i : prices) {
            //find min to buy
            if (i < k) {
                k = i;
            }

            ans = max(ans, i-k);
            //k is min 
            
        }
        return ans;
    }
};