class Solution {
    private: int helper(int row , int col, vector<vector<int>> &dp){
        // writing the base case
        if(row == 0 && col == 0){
            return 1;
        }
        if(dp[row][col] != -1) return dp[row][col];
        //doing the stuff on this index
        int left = 0;
        int right = 0;
        if(row - 1 >= 0){
            left = helper(row-1, col, dp);
        }
        if(col - 1 >= 0){
            right = helper(row, col -1, dp);
        }
        return dp[row][col] = left + right;
    }
public:
    int uniquePaths(int m, int n) {
        //writing the base case
        //write a dp array 
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1 , n-1, dp);
    }
};