class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        vector<long long> ends(26, 0);
        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long long new_ends = (total + 1) % MOD;
            total = (total + new_ends - ends[idx] + MOD) % MOD;
            ends[idx] = new_ends;
        }

        return total;
    }
};