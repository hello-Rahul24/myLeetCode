class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // Not enough cables
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Connect computers using existing cables
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            unite(u, v);
        }

        // Count number of components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        // Need components - 1 cables to connect them
        return components - 1;
    }
};