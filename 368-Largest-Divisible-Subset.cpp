class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n,-1);
         sort(nums.begin(), nums.end()); 
        int maxi = 1;
        int maxiInd = 0;
        for(int i = 1;i < n ; i++){
            for(int j = 0; j < i ; j++){
                if(nums[i]%nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                    prev[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                maxiInd = i;
            }
        }
        vector<int> ans;
        int temp = maxiInd;
        while(temp != -1){
            ans.push_back(nums[temp]);
            temp = prev[temp];
        }
        return ans;
    }
};