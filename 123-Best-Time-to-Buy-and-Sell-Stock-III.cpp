class Solution {
public:
    int helper(vector<int>& prices, int ind, int buy, int cap,vector<vector<vector<int>>>& dp){
        if(ind >= prices.size())return 0;
        if(cap == 0)return 0;
        if(dp[ind][buy][cap] != -1)return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap] = max((-prices[ind]+helper(prices, ind+1, 0,cap,dp)),helper(prices, ind+1, 1,cap,dp));
        }else{
            return dp[ind][buy][cap]= max((prices[ind]+helper(prices, ind+1, 1,cap-1,dp)),helper(prices, ind+1, 0,cap,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
       return helper(prices, 0, 1, 2,dp);
    }
};