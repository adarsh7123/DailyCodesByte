class Solution {
public:
    int climbStair(int n , unordered_map<int,int>&memo){
        if(n==0 || n==1) return 1;

        if(memo.find(n) == memo.end()){
            memo[n]= climbStair(n-1,memo) +climbStair(n-2,memo);
        }

        return memo[n];
    }
    int climbStairs(int n) {
        
        unordered_map<int,int> memo;
        return climbStair(n,memo);
    }
};