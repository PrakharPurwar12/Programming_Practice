class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int max_len = 0;

        if (counts.find(1) != counts.end()) {
            int one_count = counts[1];
            if (one_count % 2 == 0) {
                max_len = one_count - 1;
            } else {
                max_len = one_count;
            }
        }

        for (auto& pair : counts) {
            long long x = pair.first;
            if (x == 1) continue;

            int current_len = 0;
            while (counts.find(x) != counts.end() && counts[x] >= 2) {
                current_len += 2;
                x = x * x;
            }

            if (counts.find(x) != counts.end() && counts[x] >= 1) {
                current_len += 1;
            } else {
                current_len -= 1;
            }

            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};