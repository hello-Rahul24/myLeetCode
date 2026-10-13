class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<long long>square(n);
        for(int i = 0;i < n ; i++){
            square[i] = 1LL * nums[i] * nums[i];
        }
        sort(square.begin(), square.end());
        long long minhalf = 0;
        for(int i =0; i< n/2;i++){
            minhalf += square[i];
        }
        long long maxhalf = 0;
        for(int i = n/2; i < n ;i++){
            maxhalf += square[i];
        }
        return maxhalf -minhalf;
    }
};