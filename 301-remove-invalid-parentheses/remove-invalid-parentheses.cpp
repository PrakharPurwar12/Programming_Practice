class Solution {
private:
    void dfs(string s, int start, int lToRemove, int rToRemove, vector<string>& result) {
        if (lToRemove == 0 && rToRemove == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (i > start && s[i] == s[i - 1]) continue;
            
            if (s[i] == '(' || s[i] == ')') {
                string next = s.substr(0, i) + s.substr(i + 1);
                if (rToRemove > 0 && s[i] == ')') {
                    dfs(next, i, lToRemove, rToRemove - 1, result);
                } else if (lToRemove > 0 && s[i] == '(') {
                    dfs(next, i, lToRemove - 1, rToRemove, result);
                }
            }
        }
    }

    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int lToRemove = 0, rToRemove = 0;
        for (char c : s) {
            if (c == '(') {
                lToRemove++;
            } else if (c == ')') {
                if (lToRemove > 0) {
                    lToRemove--;
                } else {
                    rToRemove++;
                }
            }
        }

        vector<string> result;
        dfs(s, 0, lToRemove, rToRemove, result);
        return result;
    }
};