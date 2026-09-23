class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int>prev(amount + 1, INT_MAX);
        vector<int>curr(amount + 1, INT_MAX);
        //Only coin 0 is available
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                prev[j] = j / coins[0];
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= amount; j++) {

                // Not take
                int nottake = prev[j];

                // Take
                int take = INT_MAX;

                if (j >= coins[ind]) {
                    int result = curr[j - coins[ind]];

                    if (result != INT_MAX) {
                        take = 1 + result;
                    }
                }

                curr[j] = min(take, nottake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        return ans == INT_MAX ? -1 : ans;
    }
};