class Solution {
private: int helper(int index,vector<int>& nums , int n , vector<int> &dp){
    //base case 
    if(index >= n){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    //otherwise pick the index
    //call the left recursion
    int left =nums[index]+ helper(index + 2, nums, n, dp);
    //not pick the element
    //calll the right recursion cause we skipping the current element then we are allowed to choose the very next element
    int right = helper(index + 1 , nums, n, dp);
    //now return the max result
    return dp[index] = max(left, right);
}
public:
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // //init dp array
        // vector<int> dp(n, -1);
        // int ans = helper(0,nums,n, dp);
        // return ans;

        // // TABULATION METHOD
        // int n = nums.size();
        // vector<int> dp(n+2, 0);
        // // starting from right
        // for(int i = n-1; i >= 0 ; i--){
        //     int pick = nums[i] + dp[i + 2];
        //     int notpick = dp[i+1];
        //     dp[i] = max(pick , notpick);
        // }
        // return dp[0];

        //NOW SPACE OPTIMIZATION
        int n = nums.size();
        int front = 0;
        int front2 = 0;
        for(int i = n-1; i >= 0 ; i--){
            int pick = nums[i]+ front2;
            int notpick = front;
            int curr = max(pick , notpick);
            front2 = front;
            front = curr;
        }
        return front;
    }
};