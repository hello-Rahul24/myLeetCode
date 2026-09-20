class Solution {
public:
    long long helper(vector<vector<int>>& questions, int ind, vector<long long>& dp){
        if(ind == questions.size()-1)return questions[questions.size()-1][0];
        if(ind > questions.size()-1)return 0;
        if(dp[ind] != -1)return dp[ind];
        //solve it
        long long solve = questions[ind][0] + helper(questions, ind +questions[ind][1] +1, dp);
        long long notsolve = helper(questions, ind +1, dp);
        return dp[ind]= max(solve, notsolve);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, -1);
        
        return helper(questions, 0,dp);
    }
};