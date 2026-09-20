class Solution {
public:
    int helper(vector<int>& points, int ind,vector<int>& dp){
        if(ind == 0)return points[ind];
        if(ind < 0 )return 0;
        if(dp[ind] != -1)return dp[ind];
        int take = points[ind] + helper(points, ind-2,dp);
        int nottake = helper(points, ind-1,dp);
        return dp[ind] = max(take, nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        //index:   0  1  2  3  4
        //points:  0  0  4  9  4
        //if we take suppose index 2 it means we cant take 1 and 3 ind-1 ind+1
        int maxInd = 0;
        for(int it : nums){
            if(maxInd < it){
                maxInd = it;
            }
        }
        vector<int>points(maxInd +1, 0);
        vector<int> dp(maxInd +1, -1);
        for(int i = 0 ; i < n; i++){
            points[nums[i]] += nums[i];
        }

        return helper(points, maxInd, dp);
    }
};