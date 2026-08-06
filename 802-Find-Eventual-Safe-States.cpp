class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n);
        //create the outdegree array
        for(int i = 0 ; i < n ; i++){
            for(auto &it : graph[i]){
                //here i am not doing outdegree[it]++ cause it will calculate the indegree
                outdegree[i]++;
            }
        }
        vector<vector<int>> dummy(n);
        for(int i = 0 ; i < n ; i++){
            for(auto it : graph[i]){
                dummy[it].push_back(i);
            }
        }
        
        //add all the 0 value node to a q
        queue<int> q;
        vector<int> result;
        for(int i = 0 ; i< n ; i++){
            if(outdegree[i] == 0){
                q.push(i);
                
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto &it: dummy[node]){
                outdegree[it]--;
                if(outdegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};