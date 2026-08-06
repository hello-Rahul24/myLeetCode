class Solution {
    private:
    bool dfs(int i,int numCourses, vector<vector<int>>& adj,vector<int>& vis, vector<int>& pathVis){
        // mark the arrays
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]){
                if(dfs(it,numCourses, adj, vis, pathVis) == true) return true;
            }else if(vis[it] == 1 && pathVis[it] == 1){
                return true;
            }
        }
        pathVis[i] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //first of all this is not a adjacency list given to us
        // we have to first convert this into to adj list
        vector<vector<int>> adj(numCourses);
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        //we have to call dfs for every unvistied node
        for(int i = 0 ; i < numCourses; i++){
            if(!vis[i]){
                //if the dfs return true it means it has a cycle then we can not finish our courses
               if(dfs(i,numCourses, adj, vis, pathVis) == true)return false;
            }
        }
        return true;
    }
};