class Solution {
public:
    int helper(int ind, vector<int>& days, vector<int>& costs, vector<int>& dp){

        if(ind >= days.size())return 0;
        if(dp[ind] != -1)return dp[ind];
        int day1 = costs[0] + helper(ind+1, days, costs, dp);

        int next7 = ind;
        while(next7 < days.size() && days[ind]+7 > days[next7]){
            next7 ++;
        }
        int day2 = costs[1]+helper(next7, days, costs, dp);
        int next30 = ind;
        while(next30 < days.size() && days[ind]+30 > days[next30]){
            next30 ++;
        }
        int day3 = costs[2]+helper(next30, days, costs, dp);

        return dp[ind] = min({day1, day2,day3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return helper(0, days, costs,dp);
    }
};