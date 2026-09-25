class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
           mp[nums[i]]++;
        }
        for(auto &it: mp){
            int x = it.first; // number
            int y = it.second; //count
            pq.push({y,x});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            result.push_back(it.second);
        }
        return result;
    }
};