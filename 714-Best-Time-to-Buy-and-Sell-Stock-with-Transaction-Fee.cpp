class Solution {
public:
    int helper(vector<int>& prices, int fee, int ind, int buy, vector<vector<int>>& dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        if(buy){
            return dp[ind][buy] = max(-prices[ind]+helper(prices, fee, ind+1,0,dp),helper(prices,fee,ind+1,1,dp));
        }else{
            return dp[ind][buy] = max(((prices[ind]- fee) + helper(prices,fee, ind+1, 1,dp)), helper(prices,fee,ind+1,0,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee){
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return helper(prices,fee, 0, 1,dp);
    }
};