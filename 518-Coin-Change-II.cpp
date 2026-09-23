class Solution {
public:
    int helper(int ind , int amount, vector<int>& coins,  vector<vector<int>>& dp){
        if(amount == 0)return 1;
        if(ind == 0){
            if(amount % coins[ind]== 0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][amount]!= -1)return dp[ind][amount];
        //not pick
        int nottake = helper(ind -1, amount, coins, dp);
        int take = 0;
        if(amount >= coins[ind]){
            take = helper(ind, amount- coins[ind], coins, dp);
        }
        return dp[ind][amount] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int>(amount+1, -1));
        return helper(n-1, amount, coins, dp);
    }
};