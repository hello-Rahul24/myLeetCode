class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<char>st;
        // int count = 0;
        // for(auto &it : s){
        //     if(it == '('){
        //         st.push(it);
        //     }else{
        //         if(st.empty()){
        //             st.push(it);
        //             continue;
        //         }
        //         if(st.top() == '('){
        //             st.pop();
        //         }else{
        //             st.push(it);
        //         }
        //     }
        // }
        // return st.size();
        int open = 0, add = 0;
        for(char ch : s){
            if(ch == '('){
                open ++;
            }else{
                if(open > 0){
                    open --;
                }else{
                    add++;
                }
            }
        }
        return open + add;
    }
};