class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int n, int m, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return 1;
        }
        if(grid[i][j] == 0){
            return 1;
        }
        if(visited[i][j]){
            return 0;
        }
        visited[i][j] = true;
        int peri = 0;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1, -1};
        for(int ind = 0 ; ind < 4 ; ind++){
            int newrow = i + dx[ind];
            int newcol = j+dy[ind];
            peri += dfs(grid, visited,n, m, newrow, newcol);
        }
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int peri = dfs(grid, visited, n,m,i ,j);
                    ans = peri;
                }
            }
        }
        return ans;
    }
};