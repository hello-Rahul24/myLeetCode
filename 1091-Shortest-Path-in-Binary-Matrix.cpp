class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       //here we will use dijkstra algo with a normal q cause the edge weight is identical
       
       queue<pair<int,pair<int,int>>> q;
       int n = grid.size();
       int m = grid[0].size();
       if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
       vector<vector<int>> dist(n, vector<int>(m, 1e9));
       dist[0][0] = 1;
       q.push({1,{0,0}});
        int del[3] = {-1,0,1};
       while(!q.empty()){
        int dis = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j< 3 ; j++){
                int nrow = row + del[i];
                int ncol = col + del[j];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis + 1;
                    if(nrow == n-1 && ncol == m-1)return dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
       }
       if(n==1 ){
        return dist[n-1][m-1];
       }
        return -1;
    }
};