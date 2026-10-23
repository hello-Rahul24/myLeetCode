class Solution {
public:
    string helper(string a){
        int n = a.size();
        int j = 0 ;
        for(int i = 0 ; i < a.size(); i++){
            if(a[i] == '#'){
                if(j != 0){
                    j--;
                }else{
                    j = 0;
                }
            }else{
                if(i == j){
                    j++;
                }else{
                    a[j] = a[i];
                    j++;
                }
            }
        }
        return a.substr(0,j);
    }
    bool backspaceCompare(string s, string t) {
        return helper(s) == helper(t);
    }
};