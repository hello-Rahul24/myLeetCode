class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> st(nums.begin(), nums.end());
        // int n = st.size();
        // int i = 0;
        // for(int val : st){
        //     nums[i] = val;
        //     i++;
        // }
        // return n;
        

        // OPTIMAL APPROCAH

        int i = 0;
        for(int j = 1 ; j < nums.size(); j++){
            if(nums[i] == nums[j]){
                continue;
            }else{
                
                i++;
                nums[i] = nums[j];
            
            }
            
            
        }
        //cause i give us index but we need length
    return i+1;
    }
};