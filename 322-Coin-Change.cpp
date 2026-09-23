class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

        // Only coin 0 is available
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= amount; j++) {

                // Not take
                int nottake = dp[ind - 1][j];

                // Take
                int take = INT_MAX;

                if (j >= coins[ind]) {
                    int result = dp[ind][j - coins[ind]];

                    if (result != INT_MAX) {
                        take = 1 + result;
                    }
                }

                dp[ind][j] = min(take, nottake);
            }
        }

        int ans = dp[n - 1][amount];

        return ans == INT_MAX ? -1 : ans;
    }
};