class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') {
                total_ones++;
            }
        }

        string t = "1" + s + "1";
        vector<int> z;
        int count = 0;
        for (char c : t) {
            if (c == '0') {
                count++;
            } else {
                if (count > 0) {
                    z.push_back(count);
                    count = 0;
                }
            }
        }

        int max_gain = 0;
        for (size_t i = 0; i + 1 < z.size(); i++) {
            max_gain = max(max_gain, z[i] + z[i + 1]);
        }

        return min(n, total_ones + max_gain);
    }
};