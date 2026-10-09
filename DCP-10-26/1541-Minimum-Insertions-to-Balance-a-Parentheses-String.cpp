
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int balance = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                balance++;
            } else {
                // Ensure two consecutive closing brackets
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++; // Insert the missing ')'
                }

                if (balance > 0) {
                    balance--;
                } else {
                    ans++; // Insert a matching '('
                }
            }
        }

        return ans + 2 * balance;
    }
};
