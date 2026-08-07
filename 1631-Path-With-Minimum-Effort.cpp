class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // apply simple dijkstra algo first i have to change the condition
        // in normally there we have to do addition but here we have find max
        // diff
        // here we will not do the normal additon one by one here we will keep
        // the max jump value in the effort array , what we are keeping total
        // pathsum in the prev examples
        int n = heights.size();
        int m = heights[0].size();
        // initialize the effort array with zero
        vector<vector<int>> efforts(n, vector<int>(m, 1e9));
        // create a priority q
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        efforts[0][0] = 0;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        while (!pq.empty()) {
            int currenteffort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            // if the current effort value on the queue is bigger than the value of the efforts matrix then there is no point to compute for that value
            if(currenteffort > efforts[row][col])continue;
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                // now the conditon
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    //why abs ? because question stated maximum absolute difference which means 5 -> 2 efforts in not -3 , it is 3 
                    int effort = max(currenteffort,
                                     abs(heights[nrow][ncol] - heights[row][col]));
                    if(effort < efforts[nrow][ncol]){
                        efforts[nrow][ncol] = effort;
                    pq.push({effort, {nrow, ncol}});
                    }  
                }
            }
        }
        return efforts[n - 1][m - 1];
    }
};