class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {
                //base case
        if (i >= triangle.size() || j >= triangle[i].size())
            return 0;

//if dp previously find
        if (dp[i][j] != -1)
            return dp[i][j];


//find triangle pathcost [i+1][j] and [i+1][j+1]
        int op1 = triangle[i][j] + solve(i + 1, j, triangle, dp);
        int op2 = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);

        //return min
        return dp[i][j] = min(op1, op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size() + 1,
                               vector<int>(triangle.size() + 1, -1));
        return solve(0, 0, triangle, dp);
    }
};