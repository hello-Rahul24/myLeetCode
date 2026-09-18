class Solution {
public:
    bool check(string& a, string& b) {
        if (b.size() - a.size() != 1)
            return false;

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == a.size();
    }
    int longestStrChain(vector<string>& words) {
        // sort the array
        sort(words.begin(), words.end(),
     [](string &a, string &b) {
         return a.size() < b.size();
     });
        int n = words.size();
        vector<int> dp(n, 1);
        int maxlen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[i] < 1 + dp[j] &&
                    check(words[j],words[i])){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};