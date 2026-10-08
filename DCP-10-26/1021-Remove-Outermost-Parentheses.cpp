class Solution {
public:
    string removeOuterParentheses(string s) {
        string str = "";
        int balance = 0;
        for(char ch : s){
            if(ch == '('){
                if(balance > 0){
                    str += ch;
                }
                balance++;
            }else{
                balance --;
                if(balance > 0){
                    str +=ch;
                }
            }
        }
        return str;
    }
};