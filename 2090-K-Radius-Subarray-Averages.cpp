class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k+k+1){
            vector<int>avgs(n,-1);
            return avgs;
        }
        vector<int>avgs(n,0);
        for(int i = 0 ; i < k; i++){
            avgs[i] = -1;
            avgs[n-1-i] = -1;
        }

        int l = 0;
        int r = 0;
        int window = k + k + 1;
        long long sum = 0;
        while(r < window){
            sum += nums[r];
            r++;
        }
        long long avg = sum / window;
        avgs[k] = avg;
        while(r < n){
            k++;
            sum -= nums[l];
            l++;
            sum += nums[r];
            r++;
            avg = sum / window;
            avgs[k] = avg;
        }
        return avgs;
    }
};