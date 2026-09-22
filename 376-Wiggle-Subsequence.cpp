class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // we can see that it is only depend on two state ind, and direction
        //now if we conider up = 1 this means longest subsequece which ending is positive is 1;
        //down = 1 longest subsequece which ending is neg is 1;
        int up = 1;
        int down = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]-nums[i-1] > 0){
                //positive differnece it means we have to connect it with down to make the longest subseq and store it in up
                up = down + 1;
            }else if(nums[i]-nums[i-1] < 0){
                down = up + 1;
            }
        }
        return max(up, down);
    }
};