class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];
            int curmax = max({x, x*maxprod, x*minprod});
            int curmin = min({x, x*maxprod, x*minprod});
            maxprod = curmax;
            minprod = curmin;
            ans = max(ans, maxprod);
        }
        return ans;
    }
};