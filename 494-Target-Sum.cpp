class Solution {
private:
    int recursion(vector<int>& nums,int index, int target){
        //base case
        //here no need to have a condition like target == 0 cause target can be negetive
        if(index == 0){
            //here i have two choices one is minus and another one is plus
            int ways = 0;
            if(nums[index] == target){
             ways ++;
            }
            if(- nums[index] == target){
                ways ++;
            }
            return ways;
        }
        //explore the index
        int plus = recursion(nums, index-1, target-nums[index]);
        
        int minus = recursion(nums, index-1, target+nums[index]);

        return plus+minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return recursion(nums, n-1, target);
    }
};