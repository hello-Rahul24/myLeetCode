class Solution {
public:
    int helper(vector<int>& prices, int ind, int buy,vector<vector<int>>& dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1)return dp[ind][buy];
        // buy == 1 means we can buy
        //buy == 0 means we cant buy
        if(buy){
            return dp[ind][buy] = max(-prices[ind]+helper(prices,ind+1,0, dp), helper(prices, ind+1,1,dp));
        }else{
            return dp[ind][buy] = max(prices[ind]+helper(prices, ind+2, 1, dp),helper(prices, ind+1, 0,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        for(int ind = n-1; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                if(buy){
                    dp[ind][buy] = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }else{
                    dp[ind][buy] = max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};