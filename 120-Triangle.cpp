class Solution {
private: 
    // int helper(int row, int col,vector<vector<int>>& triangle, vector<vector<int>> &dp){
    //     //base case 
    //     if(row == triangle.size()-1) return triangle[row][col];
    //     // do the staff on the current node
    //     if(dp[row][col] != -1)return dp[row][col];
    //     int left = INT_MAX ;
    //     int right = INT_MAX;
    //     if( col <= row+1){
    //        left = triangle[row][col] + helper(row + 1, col, triangle, dp);
    //     }
    //     if(col + 1 <= row + 1){
    //        right = triangle[row][col] + helper(row + 1 , col + 1, triangle, dp);
    //     }
    //     return dp[row][col] = min(left,right);
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        //return helper(0 , 0, triangle , dp);
        //copy the last row
        for(int i = 0 ; i < n ; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i = n-2 ; i >= 0 ; i--){
            for( int j = 0 ; j < triangle[i].size(); j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];

    }
};