class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<int, int> freq;
        while(i <= j && j < nums.size()){
            freq[nums[j]]++;
            //if freq of j is bigger than k then keep increasing i until the window is valid
            while(i <= j && freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            //otherwise
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
    }
};