class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int el: nums){
            if(i == 0 || i == 1 || nums[i-2] != el){
                nums[i] = el;
                i++;
            }
        }
        return i;
    }
};