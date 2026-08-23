class Solution {
public:
    bool sumGame(string num) {
        double balance = 0.0;
        int n = num.size();
        for (int i = 0; i < n / 2; ++i) {
            balance += (num[i] == '?') ? 4.5 : (num[i] - '0');
        }
        for (int i = n / 2; i < n; ++i) {
            balance -= (num[i] == '?') ? 4.5 : (num[i] - '0');
        }
        return balance != 0.0;
    }
};