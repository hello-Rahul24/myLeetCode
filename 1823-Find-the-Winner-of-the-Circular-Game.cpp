class Solution {
public:
    int findTheWinner(int n, int k) {
        //josephus problem
        int winner = 0; // when simgle palyer it wins so ind 0
        for(int i = 2; i <= n; i++){
            winner = (winner+k)%i;
        }
        return winner+1;
    }
};