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
    vector<int>prev(2, 0);
    vector<int>curr(2,0);
    for(int ind = n-1 ; ind >= 0 ;ind--){
        for(int buy = 0 ; buy <= 1 ; buy ++){
            if(buy){
                curr[buy] = max(-prices[ind]+prev[0],prev[1]);
            }else{
                curr[buy] = max((prices[ind]- fee) + prev[1], prev[0]);
            }
        }
        prev = curr;
    }
    return curr[1];
    }
};