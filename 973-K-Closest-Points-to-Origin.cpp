#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to store pairs of {squared_distance, {x, y}}
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            int distSq = x * x + y * y;
            pq.push({distSq, {x, y}});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        // Extract the k closest points from the max-heap
        vector<vector<int>> result;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            result.push_back({it.second.first, it.second.second});
        }
        
        return result;
    }
};
