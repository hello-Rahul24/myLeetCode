class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int gap = 1;
        int remaining = n;
        bool left_to_right = true;
        while(remaining > 1){
            if(left_to_right){
                head += gap;
                left_to_right = false;
            }else{
                if(remaining % 2 == 1){
                    //odd number of el is present then change the head
                    head += gap;
                }
                left_to_right = true;
            }
            remaining = remaining / 2;
            //after each round gap doubles
            gap *= 2;
        }
        return head;
    }
};