class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>bits(32,0);
        //we have to calculate how many bits in 32 bit postion for every number
        for(int i = 0 ; i< nums.size(); i++){
            int num = nums[i];
            for(int j = 0 ; j < 32 ; j++){
                bits[j] += num >> j & 1;
            }
        }
        //it will create a array of setbit number [2,2,2,2] if k = 2 ==> we can create two number [1,1,1,1] and [1,1,1,1]
        long long sum = 0;
        const int MOD = 1e9 + 7;
        while(k--){
            long long num = 0;
            for(int i = 0 ; i < 32; i++){
                if(bits[i] > 0){
                    num += 1 << i;
                    bits[i]--;
                }
            }
            sum = (sum + (num * num))% MOD;
        }
        return sum;
    }
};