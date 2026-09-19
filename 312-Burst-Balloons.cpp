class Solution {
public:
    int helper(vector<int>& nums, int i , int j,vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1)return dp[i][j];
        long long maxcoins = LLONG_MIN;
        for(int k = i ; k <= j ; k++){
            long long coins = nums[i - 1] * nums[k] * nums[j + 1] + helper(nums, i,k-1,dp)+helper(nums,k+1, j,dp);
            if(maxcoins < coins){
                maxcoins = coins;
            }
        }
        return dp[i][j] = (int)maxcoins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(nums, 1, n, dp);
    }
};