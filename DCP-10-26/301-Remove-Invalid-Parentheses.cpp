class Solution {
public:
bool valid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(valid(curr)){
                ans.push_back(curr);
                found = true;
            }
            if(found){
                continue;
            }
            for(int i = 0 ; i < curr.size(); i++){
                if(curr[i] != '(' && curr[i] != ')'){
                    continue;
                }
                string newstring = curr.substr(0,i)+curr.substr(i+1);
                if(!visited.count(newstring)){
                    visited.insert(newstring);
                    q.push(newstring);
                }
            }
        }
        return ans;
    }
};