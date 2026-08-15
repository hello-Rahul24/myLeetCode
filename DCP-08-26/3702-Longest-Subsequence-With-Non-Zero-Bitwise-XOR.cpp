class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int value = nums[0];
        int nonzeroel = 0;
        for(int i = 1 ; i < nums.size(); i++){
            value = value ^ nums[i];
            if(nums[i] > 0) nonzeroel++;
        }
        if(value == 0 && nonzeroel > 0){
            // here the condtion nonzeroel > 0 will check that this array's every element is not zero
            //it means all the elements xor became 0 that mean if we remove any element from the array then any one specific element will not get cancle out because we removed an element 
            // it means the length will be total length - 1
            return nums.size()-1;
        }
        //if total value is not zero then the full array will be the longest length
        if(value != 0){
        return nums.size();
        }

        //now think about a specific condition where all elements are 0
        // it means if total xor will be zero 
        // then if we remove any element thereafter the total xor will be zero it means it can not produce non zero subsequence
        return 0;
    }
};