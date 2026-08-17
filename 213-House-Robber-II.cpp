class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        //here we are using two loops cause when we start from the first el then we have to go second last
        int front = 0;
        int front2 = 0;
        for(int i = n-2 ; i >= 0 ; i--){
            int pick = nums[i] + front2;
            int notpick = front;
             int curr = max(pick , notpick);
            front2 = front;
            front = curr;
        }
        // here we are going from 2nd el then we can go to last ind
        int fro = 0;
        int fro2 = 0;
        for(int i = n-1 ; i > 0 ; i--){
            int pick = nums[i] + fro2;
            int notpick = fro;
           int curr = max(pick, notpick);
            fro2 = fro;
            fro = curr;
        }
        // returning the max of two ways
        return max(front, fro);

    }
};