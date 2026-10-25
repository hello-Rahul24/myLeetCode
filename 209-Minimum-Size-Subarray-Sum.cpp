class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int minlen = INT_MAX;
        while(r < n){
            sum += nums[r];
            //r++;  this is my wrong line i am updating the r before calculating the len
            while(sum >= target){
                minlen = min(minlen, r - l +1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minlen == INT_MAX ? 0: minlen;
    }
};