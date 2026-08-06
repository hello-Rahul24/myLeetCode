class Solution {
private:
    bool dfs(int node, vector<int>& ans,vector<vector<int>>& adj, vector<int>& vis){
        //marked it as 2 it means it is visited and it is in the current path
        vis[node] = 2;
        for(auto &it: adj[node]){
            //if it not visited then call dfs
            if(!vis[it]){
                // if we add the node to ans here then order will break
                // rathar than when we return then if we add and after that if we reverse then we will get the correct order
                //ans.push_back(it);
                if(!dfs(it, ans, adj,vis))return false;
            }else if(vis[it] == 2){
                return false;
            }
        }
        ans.push_back(node);
        vis[node] = 1;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //convert it into the adj list
        vector<vector<int>> adj(numCourses);
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;
        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                if(!dfs(i, ans, adj,vis)){
                    return {};
                };
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// time complexity ==>> O(v+e) + revers O(n/2)
// space complexity ===>> O(N)