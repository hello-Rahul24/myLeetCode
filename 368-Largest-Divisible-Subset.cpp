class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        int maxIND = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                }
            }
            if(maxlen < dp[i]){
                maxlen = dp[i];
                maxIND = i;
            }
        }
        vector<int>temp;
        int dummy = maxIND;
        while(dummy != -1){
            temp.push_back(nums[dummy]);
            dummy = prev[dummy];
        }
        return temp;
    }
};