class Solution {
public:
    int helper(vector<int>& cuts, int i , int j,vector<vector<int>>& dp){
        if(j-i == 1)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int mincost = INT_MAX;
        for(int k = i+1; k <j; k++){
            int cost = cuts[j]-cuts[i]+ helper(cuts,i,k,dp)+helper(cuts,k,j,dp);
            if(mincost > cost){
                mincost = cost;
            }
        }
        return dp[i][j] = mincost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end()); 
        int len = cuts.size();
        vector<vector<int>> dp(len,vector<int>(len,-1));       
        return helper(cuts, 0, len-1,dp);
    }
};