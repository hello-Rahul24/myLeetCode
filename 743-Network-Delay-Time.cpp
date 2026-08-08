class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create a adjacency list
        vector<pair<int,int>> adj [n+1];
        for(auto &it : times){
            int source = it[0];
            int target = it[1];
            int time = it[2];
            adj[source].push_back({target, time});
        }
        //define a priority queue with this sturc [time , node]
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // define a minimum time array
        vector<int> minitime(n+1, 1e9);
        minitime[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int currtime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(currtime > minitime[node])continue;
            for(auto it: adj[node]){
                int nextNode = it.first;
                int nextTime = it.second;
                if(currtime + nextTime < minitime[nextNode]){
                    minitime[nextNode] = currtime + nextTime;
                    pq.push({currtime + nextTime , nextNode});
                }
            }
        }
        int value = 0;
        for(int i = 1 ; i < n+1 ; i++){
            if(minitime[i] == 1e9){
                return -1;
            }else{
                value = max(value , minitime[i]);
            }
        }
        return value;
    }
};