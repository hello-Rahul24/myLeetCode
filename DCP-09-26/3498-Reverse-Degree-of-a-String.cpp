class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = 0 ;i < s.size();i++){
            int reversedval = 26 - (s[i]-'a');
            int product = reversedval*(i+1); 
            ans += product;
        }
        return ans;
    }
};