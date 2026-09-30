class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build adjacency list
        vector<vector<int>> adj(n);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &x : adj[curr]){
                if(visited[x]!= true){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        if(visited[destination] == false){
            return false;
        }
        return true;
    }
};