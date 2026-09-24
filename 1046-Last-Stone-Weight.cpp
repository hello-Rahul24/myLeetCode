class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int it : stones){
            pq.push(it);
        }
        while(pq.size() > 1){
            int firststone = pq.top();
            pq.pop();

            int secondstone = pq.top();
            pq.pop();

            pq.push(firststone - secondstone);
            
        }
        return pq.top();
    }
};