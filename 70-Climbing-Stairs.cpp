class Solution {
public:
    // it is a fibonacci question where we apply dp 
    int climbStairs(int n) {
        int prev = 1;
        int prev2 = 1;
        for(int i = 2; i <= n ; i++){
            int curr = prev + prev2;
            prev2 = prev ;
            prev = curr;
        }
        return prev;

    }
};