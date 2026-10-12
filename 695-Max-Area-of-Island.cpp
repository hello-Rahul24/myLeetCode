class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int n,
            int m, int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >= m){
            return 0;
        }
        if(grid[i][j] == 0 || visited[i][j]){
            return 0;
        }
        visited[i][j] = true;

        int cnt = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            cnt += dfs(grid, visited, n, m, ni, nj);
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxcount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int cnt = dfs(grid, visited, n, m, i, j);
                    maxcount = max(maxcount, cnt);
                }
            }
        }
        return maxcount;
    }
};