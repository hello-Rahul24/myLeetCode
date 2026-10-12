class Solution {
public:
    int delrow[4] = {1,-1,0,0};
    int delcol[4] = {0,0,1,-1};
    void dfs(vector<vector<int>>& grid, int n, int m, int row , int col){
        if(row < 0 || col < 0 || row >= n || col >= m ){
            return;
        }
        if(grid[row][col] == 1)return;
        grid[row][col] = 1;
        for(int i = 0 ; i < 4 ; i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            dfs(grid, n,m,newrow, newcol);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //for first row and last row
        for(int i = 0 ; i < m ; i++){
            if(grid[0][i] == 0){
                dfs(grid, n, m, 0,i);
            }
            if(grid[n-1][i]==0){
                dfs(grid,n,m,n-1,i);
            }
        }
        //for first col and last col
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 0){
                dfs(grid,n,m,i,0);
            }
            if(grid[i][m-1] == 0){
                dfs(grid,n,m,i,m-1);
            }
        }
        int count = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    count ++;
                    dfs(grid, n, m, i, j);
                }
            }
        }
        return count;
    }
};