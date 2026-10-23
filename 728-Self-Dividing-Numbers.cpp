class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            int n = i;
            int num = i;
            bool valid = true;
            while(n > 0){
                int digit = n % 10;
                if(digit == 0){
                    valid = false;
                    break;
                }
                if(num % digit != 0){
                    valid = false;
                    break;
                }
                n = n/10;
            }
            if(valid){
                ans.push_back(num);
            }
        }
        return ans;
    }
};