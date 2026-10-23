class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = 4294967295;
        for(int i = 0 ;i < nums.size(); i++){
            if(nums[i] != i){
                ans = ans & nums[i];
            }
        }
        return ans == -1 ? 0 : ans;
    }
};