class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1){
            return s;
        }
        vector<string> rows(numRows);//creating every string for each row
        int currentRow = 0;
        int direction = 1; // 1 ==> down -1 ==> up
        for(int i = 0; i < n ; i++){
            rows[currentRow] += s[i];
            //if it hits last row change it direction 
            if(currentRow == numRows -1){
                direction = -1;
            }
            if(currentRow == 0){
                direction = 1;
            }
            currentRow += direction;
        }
        string res = "";
        for(auto s : rows){
            res += s;
        }
        return res;
    }
};