class Solution {
public:
    bool is_vowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int count = 0;
        while (r < k) {
            if (is_vowel(s[r])) {
                count++;
            }
            r++;
        }
        int maxcount = count;
        while (r < n) {
            if (is_vowel(s[l])) {
                count--;
            }
            l++;
            if (is_vowel(s[r])) {
                count++;
            }
            r++;
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};