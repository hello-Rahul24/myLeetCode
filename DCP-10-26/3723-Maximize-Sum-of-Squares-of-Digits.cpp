class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        //it is a greedy based problem we have to choose the biggest first number if it is greater than 9 then the first el is always 9
        if(num == 1 && sum > 9){
            return "";
        }
        string ans = "";
        while(num--){
            if(sum >= 9){
                sum -= 9;
                ans += '9';
            }else if( sum == 0){
                ans += '0';
            }else{
                ans += to_string(sum);
                sum = 0;
            }
        }

        return sum == 0 ? ans : "";
    }
};