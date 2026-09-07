class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //its similar like move zeros to end
        // find the first target el index
        int j = -1;
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] == val){
                j = i;
                break;
            }
        }
        if(j == -1) return nums.size();
        for(int i = j+1; i < nums.size(); i++){
            if(nums[i] != val){
                swap(nums[j], nums[i]);
                j++;
            }
        }
        return j;
    }
};