class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_chars = 0;
        int odd_idx = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_chars++;
                odd_idx = i;
            }
        }

        if ((n % 2 == 0 && odd_chars != 0) || (n % 2 == 1 && odd_chars != 1)) {
            return "";
        }

        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        int half_len = n / 2;

        auto build_palindrome = [&](const string& first_half) {
            string res = first_half;
            if (n % 2 == 1) {
                res += (char)('a' + odd_idx);
            }
            string rev = first_half;
            reverse(rev.begin(), rev.end());
            res += rev;
            return res;
        };

        auto make_smallest = [&](int pos, vector<int>& hc) {
            string first_half = "";
            first_half.resize(half_len);
            for (int i = 0; i < pos; ++i) {
                first_half[i] = target[i];
            }
            int cur = 0;
            for (int i = pos; i < half_len; ++i) {
                while (cur < 26 && hc[cur] == 0) {
                    cur++;
                }
                first_half[i] = (char)('a' + cur);
                hc[cur]--;
            }
            return build_palindrome(first_half);
        };

        vector<int> cur_hc = half_count;
        bool can_match_prefix = true;
        for (int i = 0; i < half_len; ++i) {
            int c = target[i] - 'a';
            if (cur_hc[c] > 0) {
                cur_hc[c]--;
            } else {
                can_match_prefix = false;
                break;
            }
        }

        if (can_match_prefix) {
            string p = build_palindrome(target.substr(0, half_len));
            if (p > target) {
                return p;
            }
        }

        for (int i = half_len - 1; i >= 0; --i) {
            vector<int> temp_hc = half_count;
            bool valid_prefix = true;
            for (int j = 0; j < i; ++j) {
                int c = target[j] - 'a';
                if (temp_hc[c] > 0) {
                    temp_hc[c]--;
                } else {
                    valid_prefix = false;
                    break;
                }
            }

            if (!valid_prefix) continue;

            int next_char = target[i] - 'a' + 1;
            while (next_char < 26 && temp_hc[next_char] == 0) {
                next_char++;
            }

            if (next_char < 26) {
                temp_hc[next_char]--;
                string first_half = target.substr(0, i);
                first_half += (char)('a' + next_char);
                int cur = 0;
                for (int j = i + 1; j < half_len; ++j) {
                    while (cur < 26 && temp_hc[cur] == 0) {
                        cur++;
                    }
                    first_half += (char)('a' + cur);
                    temp_hc[cur]--;
                }
                return build_palindrome(first_half);
            }
        }

        return "";
    }
};