class Solution {
public:
    long long MOD = 1e9 + 7;
    long long helper(int n, vector<long long>& dp) {
        if (n == 0) return 1;
        if (n == 1) return 2;

        if (dp[n] != -1)
            return dp[n];
        long long take = helper(n - 2, dp);
        long long nottake = helper(n - 1, dp);
        return dp[n] = (take + nottake) % MOD;
    }

    int countHousePlacements(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2 ; i < n+1; i++){
            long long take = dp[i-2];
            long long nottake = dp[i - 1];
            dp[i] = (take + nottake) % MOD;
        }
        long long oneside = dp[n];
        return (1LL * oneside * oneside) % MOD;
    }
};