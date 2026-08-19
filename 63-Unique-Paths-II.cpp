class Solution {
private: 
    int helper(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        //if it hits by a obstacle
        if(obstacleGrid[row][col] == 1){
            return 0;
        }
        //if it hits 0,0 then return 1;
        if(row == 0 && col == 0){
            return 1;
        }
        
        //check in the dp array
        if(dp[row][col] != -1) return dp[row][col];

        int left = 0;
        int right = 0;
        if(row - 1 >= 0){
            left = helper(row -1 , col,obstacleGrid, dp);
        }
        if(col - 1 >= 0){
            right = helper(row , col - 1, obstacleGrid, dp);
        }
        return dp[row][col] = left + right; 
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        //instead of doing all this stuff, move the obstacle check to the first in recursive function
        
        // if(n == 1 && m == 1) {
        //     if(obstacleGrid[0][0] == 0){
        //         return 1;
        //     }else{
        //         return 0;
        //     }
        // }
        // if(obstacleGrid[0][0] == 1)return 0;
        // if(obstacleGrid[n-1][m-1] == 1)return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, obstacleGrid, dp);
    }
};