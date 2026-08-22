class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        //what is last word is space ??
        int ind = n-1;
        while(s[ind] == ' ' && ind > 0){
            ind --;
        }
        int ans = 0;
        // for(int i = ind ; i >= 0 ; i--){
        //     if(s[i] == ' '){
        //         ans = ind - i;
        //         break;
        //     }
        // }
        //what is there is a single word ??
        //if(ans == 0 )return ind + 1;
        while(ind >= 0 && s[ind] != ' '){
            ans++;
            ind--;
        }
        return ans;
    }
};