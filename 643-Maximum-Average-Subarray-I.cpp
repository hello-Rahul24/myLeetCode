class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //fixed sized silding window approach
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        while(r < k){
            sum += nums[r];
            r++;
        }
        double maxavg = (double)sum / k;

        while(r < n){
            sum -= nums[l];
            l++;
            sum += nums[r];
            r++;
            double avg = (double)sum / k;
            maxavg = max(avg, maxavg);
        }
        return maxavg;
    }
};