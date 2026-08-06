class Solution {
private:
    int getProduct(int n){
        int product = 1;
        while(n > 0){
            int digit = n % 10;
            product = product * digit;
            n = n / 10;
        }
        return product;
    }
public:
    int smallestNumber(int n, int t) {
        //whenever a zero comes in the entire product goes zero for that the loop max can run till 10
        for(int i = 1 ; i <= 10 ; i++){
            int product = getProduct(n);
            if(product % t == 0) {
                break;
            }
            // increasing the value
            n = n + 1;
        }
        return n;
    }
};