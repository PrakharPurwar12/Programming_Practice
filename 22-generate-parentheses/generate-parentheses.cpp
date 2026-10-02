class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
    
private:
    void generate(int n, int open, int close, string current, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(current);
            return;
        }
        if (open < n) {
            generate(n, open + 1, close, current + "(", result);
        }
        if (close < open) {
            generate(n, open, close + 1, current + ")", result);
        }
    }
};