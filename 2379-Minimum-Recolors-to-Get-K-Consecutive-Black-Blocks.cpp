class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int left = 0;
        int right = 0;
        int wcount = 0;
        while(right < k){
            if(blocks[right] == 'W'){
                wcount ++;
            }
            right ++;
        }
        int minicount = wcount;
        while(right < n){
            if(blocks[left] == 'W'){
                wcount --;
            }
            left ++;
            //right pointer already in the next el cause the upper loop breaks for right point reaches k 
            if(blocks[right] == 'W'){
                wcount ++;
            }
            right ++;
            minicount = min(minicount, wcount);
        }
        return minicount;
    }
};