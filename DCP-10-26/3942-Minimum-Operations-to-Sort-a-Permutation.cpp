class Solution {
public:
    bool check_increasing(vector<int>& nums, int minInd, int n){
        int breakind;
        for(int i = minInd; i < minInd+n; i++){
            if(nums[(i+1)%n] - 1 != nums[i%n]){
                breakind = (i+1)%n;
                break;
            }
        }
        if(minInd == breakind){
            return true;
        }
        return false;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        //step 1: find the minInd
        int minInd;
        for(int i = 0 ;i < n ; i++){
            if(nums[i] == 0){
                minInd = i;
                break;
            }
        }
        //step 2: find is it increasing array or decreasing
        bool is_increasing = check_increasing(nums,minInd,n);
        bool is_decreasing = false;
        if(!is_increasing){
            reverse(nums.begin(),nums.end());
            minInd = n -minInd -1;
            is_decreasing = check_increasing(nums,minInd,n);
        }
        if(!is_increasing && !is_decreasing){
            return -1;
        }
        int ans = INT_MAX;
        if(is_increasing){
            ans = min(minInd, 2+(n-minInd));
        }
        if(is_decreasing){
            ans = min(1 + minInd, 1+n-minInd);
        }
        return ans;
    }
};