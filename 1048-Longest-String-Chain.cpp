class Solution {
public:
    static bool comparator(string word1, string word2){
        return word1.size() < word2.size();
    }
    bool check(string one , string two){
        if(two.size() - one.size() != 1)return false;
        int i = 0;
        int j = 0;
        while(i < one.size() && j < two.size()){
            if(one[i] == two[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
       return i == one.size();
    }
    int longestStrChain(vector<string>& words) {
        //we have to sort this array by length
        sort(words.begin(), words.end(),comparator);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxlen = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(check(words[j], words[i])){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if(maxlen < dp[i]){
                maxlen = dp[i];
            }
        }
        return maxlen;
    }
};