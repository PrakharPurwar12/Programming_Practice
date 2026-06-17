#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lengths(n + 1, 0);
        long long current_len = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                current_len++;
            } else if (s[i] == '*') {
                if (current_len > 0) {
                    current_len--;
                }
            } else if (s[i] == '#') {
                current_len *= 2;
            } else if (s[i] == '%') {

            }
            lengths[i + 1] = current_len;
        }

        if (k >= current_len) {
            return '.';
        }

        for (int i = n - 1; i >= 0; --i) {
            long long prev_len = lengths[i];

            if (s[i] >= 'a' && s[i] <= 'z') {
                if (k == prev_len) {
                    return s[i];
                }
            } else if (s[i] == '*') {
                
            } else if (s[i] == '#') {
                k %= prev_len;
            } else if (s[i] == '%') {
                k = prev_len - 1 - k;
            }
        }

        return '.';
    }
};