class Solution {
public:
    void recursion(vector<int>& nums,set<vector<int>>&set,vector<bool>& visited, vector<int>& temp){
        if(temp.size() == nums.size()){
            set.insert(temp);
            return;
        }
        for(int i = 0 ; i < visited.size(); i++){
            if(visited[i]){
                continue;
            }
            visited[i] = true;
            temp.push_back(nums[i]);
            recursion(nums,set,visited,temp);
            visited[i] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> st;
        vector<bool> visited(nums.size(), false);
        vector<int> temp;
        recursion(nums, st, visited, temp);
        for(auto &it : st){
            result.push_back(it);
        }
        return result;
    }
};