class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;

        // Adjacency list: {neighbor, time}
        vector<vector<pair<int, int>>> adj(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // {distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            // Ignore outdated priority queue entries
            if (currDist > dist[node])
                continue;

            for (auto [nextNode, time] : adj[node]) {
                long long newDist = currDist + time;

                // Found a shorter path
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    ways[nextNode] = ways[node];

                    pq.push({newDist, nextNode});
                }

                // Found another shortest path
                else if (newDist == dist[nextNode]) {
                    //it means already there is a way suppose 2 and another way adds it can be 2 total 4
                    ways[nextNode] =
                        (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};