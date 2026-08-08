class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        //making the adj list
        for(auto &it : flights){
            int from = it[0];
            int to = it[1];
            int price = it[2];
            adj[from].push_back({to, price});
        }
        vector<int> minprice(n, 1e9);
        // define a queue [stops,node,price]
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            if(node == dst) continue;
            for(auto next : adj[node]){
                int to = next.first;
                int cost = next.second;
                // condition 
                if(price + cost < minprice[to] && stops <= k){
                    minprice[to] = price + cost;
                    q.push({stops+1,{to,price + cost}});
                }
            }
        }
        if(minprice[dst] == 1e9){
            return -1;
        }
        return minprice[dst];
    }
};