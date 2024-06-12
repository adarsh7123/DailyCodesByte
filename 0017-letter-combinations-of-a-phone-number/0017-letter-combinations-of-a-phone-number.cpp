class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        string phone_map[] = {"abc", "def",  "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;

        backtrack("", digits, phone_map, output);
        return output;
    }

private:
    void backtrack(string combination, string nextDigit, string phone_map[],
                   vector<string>& output) {
        if (nextDigit.empty()) {
            output.push_back(combination);

        } else {
            string letters = phone_map[nextDigit[0] - '2'];
            for (char letter : letters) {
                backtrack(combination + letter, nextDigit.substr(1), phone_map,
                          output);
            }
        }
    }
};