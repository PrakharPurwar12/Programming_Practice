class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 0 || sum > 9 * num) return "";
        string ans(num, '0');
        int rem = sum;
        for (int i = 0; i < num; ++i) {
            int d = min(9, rem);
            ans[i] = '0' + d;
            rem -= d;
        }
        if (rem > 0) return "";
        return ans;
    }
};