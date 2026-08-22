class Solution {
public:
    int strStr(string haystack, string needle) {

        //  I HAVE TO LEARN KMP ALGO FOR THIS QUESTIONS OPTIMAL SOLUTION 
        // KNUTH MORRIS ALGO
        int j = 0;
        for(int i = 0 ; i < haystack.size() ; i++){
            int oldI = i;
            if(haystack[i] == needle[j]){
                int ans = i;
                while(i < haystack.size() && j < needle.size() && haystack[i] == needle[j]){
                    i++;
                    j++;
                }
              if(j == needle.size()){
                return ans;

                }
            }
            i = oldI;
            j = 0;
        }
        return -1;
    }
};