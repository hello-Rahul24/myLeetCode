class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // by sorting it will not work cause it needs index as answer here we have to approch as prefix
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end()){
                ans.push_back(mp[rem]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};