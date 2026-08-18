class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        // first maintain a freq array
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        // if k == 1 it means return the max number which does not repeat
        int value = -1;
        if (k == 1) {
            for (auto& it : mp) {
                if(it.second == 1 && it.first > value){
                    value = it.first;
                }
            }
        }else if( k == nums.size()){
            for(int i = 0 ; i < nums.size(); i++){
                if(value < nums[i]){
                    value = nums[i];
                }
            }
        }else{
            // we have to return nums[0] or nums[n-1] based on size and freq
            if(mp[nums[0]] == 1 && mp[nums[n-1]] != 1){
                value = nums[0];
            }else if(mp[nums[0]] != 1 && mp[nums[n-1]] == 1){
                value = nums[n-1];
            }else if(mp[nums[0]] == 1 && mp[nums[n-1]] == 1){
                value = max(nums[0], nums[n-1]);
            }
        }
        return value;
    }
};