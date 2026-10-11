class Solution {
public:
    bool judgeSquareSum(int c) {
        int low =0;
        int high = sqrt(c);
        while(low <= high){
            long long val = (long long)low*low + (long long)high*high;
            
            if(val > c){
                high--;
            }else if(val < c){
                low ++;
            }else{
                return true;
            }
        }
        return false;
    }
};