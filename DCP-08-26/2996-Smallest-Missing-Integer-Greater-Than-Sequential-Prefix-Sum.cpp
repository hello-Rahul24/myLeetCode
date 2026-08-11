class Solution {
public:
    int missingInteger(vector<int>& nums) {
        long long sum = nums[0];

        // Find sum of longest sequential prefix
        int i = 1;

        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        // Store all numbers
        unordered_set<int> st(nums.begin(), nums.end());

        // Find smallest missing number >= sum
        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};