class Solution {
public:
    int minOperations(string s) {
        char mx = 'a', mn = 'z';
        int n = s.length();
        for (int i = 0; i < n; i++) {
            mx = max(mx, s[i]);
            mn = min(mn, s[i]);
        }
        string temp = s;
        sort(temp.begin(), temp.end());
        //if already sorted
        if(temp == s){
            return 0;
        }
        //if two char presents and not sorted
        if (n == 2) {
            return -1;
        }
        //if starting char is smallest or last char is largest
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        //if any mid char is minimum char or max char then 
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        //if we have maxel in first pos or minel in last pos then we ll need 3 operations ex: edc
        return 3;
    }
};