class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i =0 ;
        int j = 0;
        int ans = 0;
        unordered_map <int, int> freq;
        while(i <= j && j < s.size()){
            freq[s[j]]++;
            while(freq[s[j]]>2){
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};