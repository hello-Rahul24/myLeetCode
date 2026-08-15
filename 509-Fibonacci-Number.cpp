class Solution {
public:
    int fib(int n) {
        // NORMAL RECURSIVE SOLUTION
        // if(n <= 1) return n ;
        // return fib(n-1)+ fib(n-2);


        //THIS IS DP SOLUTION BY REDUCING SPACE AND TIME TO 0[N] AND SC => 0[1]
        int prev = 0;
        int prev2 = 1;
        for(int i = 1 ; i <= n ; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        };
        return prev;
    }
};