class Solution {
    static const long long LIMIT = 1000001LL;

    long long countWays(const vector<int>& cnt, int total) {
        long long res = 1;
        int remaining = total;
        for (int i = 0; i < 26; i++) {
            int c = cnt[i];
            for (int j = 1; j <= c; j++) {
                res = res * (remaining - c + j) / j;
                if (res > LIMIT) return LIMIT;
            }
            remaining -= c;
        }
        return min(res, LIMIT);
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> half(26, 0);
        int len = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
            if (freq[i] % 2 != 0) {
                mid = 'a' + i;
            }
        }

        if (countWays(half, len) < k) {
            return "";
        }

        string left = "";
        long long target_k = k;

        for (int pos = 0; pos < len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;
                long long ways = countWays(half, len - pos - 1);

                if (ways >= target_k) {
                    left += (char)('a' + ch);
                    break;
                }

                target_k -= ways;
                half[ch]++;
            }
        }

        string ans = left;
        if (mid != 0) {
            ans += mid;
        }
        string rev_left = left;
        reverse(rev_left.begin(), rev_left.end());
        ans += rev_left;

        return ans;
    }
};