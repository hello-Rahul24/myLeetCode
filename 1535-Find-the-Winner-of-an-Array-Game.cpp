class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int current_winner = arr[0];
        int streak = 0;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > current_winner){
                current_winner = arr[i];
                streak = 1;
            }else{
                streak ++;
            }
            if(streak == k){
                break;
            }
        }
        return current_winner;
    }
};