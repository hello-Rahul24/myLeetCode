class Solution {
public:
    // int helper(string s, string t, int n, int m, vector<vector<int>>& dp) {
    //     if (n == 0 || m == 0)
    //         return 0;
    //     if (dp[n][m] != -1)
    //         return dp[n][m];

    //     if (s[n - 1] == t[m - 1]) {
    //         return dp[n][m] = 1 + helper(s, t, n - 1, m - 1, dp);
    //     }
    //     return dp[n][m] =
    //                max(helper(s, t, n - 1, m, dp), helper(s, t, n, m - 1, dp));
    // }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j],
                                      dp[i][j - 1]);
                }
            }
        }
         return dp[n][m];
    }
};