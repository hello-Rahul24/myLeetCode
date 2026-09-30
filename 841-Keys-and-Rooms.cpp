class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool>& visited,int start){
        visited[start] = true;
        for(auto it : rooms[start]){
            if(visited[it] == false){
                dfs(rooms, visited, it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        dfs(rooms,visited,0);
        for(auto it : visited){
            if(it == false){
                return false;
            }
        }
        return true;
    }
};