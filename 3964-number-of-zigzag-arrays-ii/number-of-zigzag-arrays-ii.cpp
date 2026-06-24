class Solution {
public:
    long long MOD = 1e9 + 7;

    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int sz = A.size();
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) {
            for (int k = 0; k < sz; ++k) {
                if (A[i][k] == 0) continue; 
                for (int j = 0; j < sz; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> base, long long exp) {
        int sz = base.size();
        vector<vector<long long>> res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) res[i][i] = 1; 

        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;

        int m = r - l + 1;
        int states = 2 * m;

        vector<long long> start_vec(states, 0);
        for (int y = 0; y < m; ++y) {
            start_vec[y] = y % MOD;             
            start_vec[m + y] = (m - 1 - y) % MOD; 
        }

        if (n == 2) {
            long long ans = 0;
            for (long long val : start_vec) ans = (ans + val) % MOD;
            return ans;
        }

        vector<vector<long long>> T(states, vector<long long>(states, 0));
        for (int z = 0; z < m; ++z) {
            for (int y = 0; y < z; ++y) {
                T[z][m + y] = 1;
            }
            for (int y = z + 1; y < m; ++y) {
                T[m + z][y] = 1;
            }
        }

        vector<vector<long long>> T_pow = power(T, n - 2);

        long long ans = 0;
        for (int i = 0; i < states; ++i) {
            long long final_state_val = 0;
            for (int j = 0; j < states; ++j) {
                final_state_val = (final_state_val + T_pow[i][j] * start_vec[j]) % MOD;
            }
            ans = (ans + final_state_val) % MOD;
        }

        return ans;
    }
};