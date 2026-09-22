class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curmaxsum = 0;
        int curminsum = 0;

        int maxsum = INT_MIN;
        int minsum = INT_MAX;
        for(auto it: nums){
            curmaxsum = max(curmaxsum+it, it);
            maxsum = max(maxsum , curmaxsum);
            curminsum = min(curminsum+it,it);
            minsum = min(minsum, curminsum);
        }
        return max(abs(maxsum),abs(minsum));
    }
};