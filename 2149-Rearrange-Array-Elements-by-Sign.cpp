class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n, 0);
        int pos = 0;
        int neg = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                res[neg] = nums[i];
                neg = neg + 2;
            }
            if(nums[i] >= 0){
                res[pos] = nums[i];
                pos = pos+2;
            }
        }
        return res;
    }
};