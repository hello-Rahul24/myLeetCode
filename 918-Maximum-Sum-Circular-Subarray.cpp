class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // total array sum - min sub array sum
        int sum1 = 0;
        int minsum = INT_MAX;
        int total = 0;
        int maxsum = INT_MIN;
        int sum2 = 0;
        for(auto it : nums){
            total += it;
            if(sum2 < 0)sum2 = 0;
            if(sum1 > 0) sum1 = 0;
            sum1 += it;
            sum2 += it;
            if(sum2 > maxsum){
                maxsum = sum2;
            }
            if(sum1 < minsum){
                minsum = sum1;
            }
        }
        // All elements are negative
        if(maxsum < 0)
            return maxsum;

        return max(maxsum, total - minsum);
    }
};