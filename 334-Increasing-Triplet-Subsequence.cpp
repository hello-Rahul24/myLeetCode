class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // THIS IS LIS APPROCH
        // vector<int>temp;
        // temp.push_back(nums[0]);
        // for(int i = 1 ; i < nums.size(); i++){
        //     if(nums[i] > temp.back()){
        //         temp.push_back(nums[i]);
        //     }else{
        //         auto ind = lower_bound(temp.begin(), temp.end(), nums[i]);//it will give interaton
        //         *ind = nums[i];
        //     }
        //     if(temp.size() >= 3)return true;
        // }
        // return false;
        
        // WE CAN SOLVE IT MORE EFFICIENTLY
        if(nums.size() < 3)return false;
        int a = INT_MAX;
        int b = INT_MAX;
        for(auto it : nums){
            if(it <= a){
                a = it;
            }else if(it <= b){
                b = it;
            }else{
 return true;
            }
           
        }
        return false;
    }
};