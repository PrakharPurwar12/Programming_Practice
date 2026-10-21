class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;
        
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        
        if (s[0] == mn || s[n - 1] == mx) return 1;
        
        bool has_mn_proper_prefix = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) {
                has_mn_proper_prefix = true;
                break;
            }
        }
        
        bool has_mx_proper_suffix = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) {
                has_mx_proper_suffix = true;
                break;
            }
        }
        
        if (!has_mn_proper_prefix && !has_mx_proper_suffix) return 3;
        
        return 2;
    }
};