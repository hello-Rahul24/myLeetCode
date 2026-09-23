class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> dp;
        int maxlen = 1;
        for(auto it: arr){
            dp[it] = dp[it - difference] + 1;
            maxlen = max(maxlen, dp[it]);
        }
        return maxlen;
    }
};