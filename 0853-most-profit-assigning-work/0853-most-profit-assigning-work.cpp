class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int maxDifficulty = *max_element(
            difficulty.begin(), difficulty.end()); // find max difficulty

        vector<int> maxProfitUpToDifficulty(
            maxDifficulty + 1,
            0); // array of max profit upto the max Difficulty

        // assign max Profit to each Difficulty
        for (int i = 0; i < difficulty.size(); ++i) {
            maxProfitUpToDifficulty[difficulty[i]] =
                max(maxProfitUpToDifficulty[difficulty[i]], profit[i]);
        }

        // assign max Profit to each Difficulty to the which difficulty which
        // not inculde in array of difficulty
        for (int i = 1; i <= maxDifficulty; ++i) {
            maxProfitUpToDifficulty[i] =
                max(maxProfitUpToDifficulty[i], maxProfitUpToDifficulty[i - 1]);
        }

        // count profit

        int totalProfit = 0;
        for (int ability : worker) {
            if (ability > maxDifficulty) {
                totalProfit += maxProfitUpToDifficulty[maxDifficulty];
            } else {
                totalProfit += maxProfitUpToDifficulty[ability];
            }
        }

        return totalProfit;
    }
};