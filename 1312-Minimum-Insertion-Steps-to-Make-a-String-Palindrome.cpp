class Solution {
public:
    int helper(string s , string t,int ind1,int ind2,vector<vector<int>>& dp){
        //base case
        if(ind1 < 0 || ind2 < 0)return 0;
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = 1 + helper(s, t, ind1-1, ind2-1,dp);
        }
        return dp[ind1][ind2]= max(helper(s, t, ind1-1 , ind2, dp), helper(s,t, ind1, ind2-1, dp));
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        //vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
        // vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        // //base case
        // for(int i = 0 ; i < n ; i++){
        //     prev[]
        // }
        for(int ind1 = 1; ind1 <= n ; ind1 ++){
            int prev = 0;
            for(int ind2 = 1;ind2 <= n ; ind2 ++){
                int temp = curr[ind2];
            if(s[ind1-1] == t[ind2-1]){
                curr[ind2] = 1 + prev;
            }else{
                curr[ind2]= max(curr[ind2], curr[ind2-1]);
            }
        prev = temp;
            }
        }
        int val = curr[n];  
        return  n-val;
    }
};