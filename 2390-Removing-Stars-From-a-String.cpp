class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '*'){
                j--;
            }else{//char is not astrics
                //if the two ptrs i and j is same then do not have to do anything
                if(i == j){
                    j++;
                }else{
                    s[j] = s[i];
                    j++;
                }
            }
        }
        return s.substr(0,j);
    }
};