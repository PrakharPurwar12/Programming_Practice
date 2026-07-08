#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        vector<int> digits;
        vector<int> orig_to_comp(m, -1);
        
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                orig_to_comp[i] = digits.size();
                digits.push_back(s[i] - '0');
            }
        }

        int n = digits.size();
        if (n == 0) {
            return vector<int>(queries.size(), 0);
        }

        vector<int> next_nz(m, -1);
        int last = -1;
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] != '0') {
                last = orig_to_comp[i];
            }
            next_nz[i] = last;
        }

        vector<int> prev_nz(m, -1);
        last = -1;
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                last = orig_to_comp[i];
            }
            prev_nz[i] = last;
        }

        vector<long long> pref_sum(n + 1, 0);
        vector<long long> pref_val(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            pref_sum[i + 1] = pref_sum[i] + digits[i];
            pref_val[i + 1] = (pref_val[i] * 10 + digits[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int L = next_nz[l];
            int R = prev_nz[r];

            if (L == -1 || R == -1 || L > R) {
                answer.push_back(0);
                continue;
            }

            long long current_sum = pref_sum[R + 1] - pref_sum[L];
            
            long long x = (pref_val[R + 1] - (pref_val[L] * pow10[R - L + 1]) % MOD + MOD) % MOD;
            
            long long ans = (x * current_sum) % MOD;
            answer.push_back(ans);
        }

        return answer;
    }
};