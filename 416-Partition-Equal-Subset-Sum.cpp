class Solution {
private:
    // bool recursion(vector<int>& nums, int index, int target) {
    //     if (target == 0)
    //         return true;
    //     if (index == 0)
    //         return (target == nums[index]);

    //     bool notpick = recursion(nums, index - 1, target);
    //     bool pick = false;
    //     if (target > nums[index]) {
    //         pick = recursion(nums, index - 1, target - nums[index]);
    //     }
    //     return pick || notpick;
    // }

public:
    bool canPartition(vector<int>& nums) {
        // this is the same problem as find subset sum of target
        //  here it is mentioned that two subarray with equal some so it means
        //  the entire array sum should be even cause we have to split it in
        //  half
        // so if it come as odd number then immidiatle retunr false otherwise
        // find a subset of target of totalsum /2
        //  here we are not saying that if the total sum became even it doesnt
        //  guranteed that it can be partitioned but here we have to find out if
        //  we can do partitioning thats why we have to find a subset of
        //  totalsum/2 if we can find then there will be a another subset for
        //  sure partition the array into two subsets That means every element
        //  must belong to one of the two subsets.

        int totalsum = 0;
        for (int x : nums) {
            totalsum += x;
        }
        if (totalsum % 2 != 0) {
            return false;
        }
        int target = totalsum / 2;
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        prev[0] = curr[0] = true;
        // here this important checks  test case [9,5];
        if (nums[0] <= target) {
            prev[nums[0]] = true;
        }
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notpick = prev[j];
                bool pick = false;
                if (j >= nums[i]) {
                    pick = prev[j - nums[i]];
                }
                curr[j] = pick || notpick;
            }
            prev = curr;
        }
        return prev[target];
    }
};