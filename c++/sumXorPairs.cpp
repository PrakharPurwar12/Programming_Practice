#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        long long total = 0;
        int n = arr.size();
        // Count how many numbers have each bit set.
        long long bitCount[32] = {0};
        for (int x : arr) {
            for (int bit = 0; bit < 32; ++bit) {
                if (x & (1LL << bit)) {
                    bitCount[bit]++;
                }
            }
        }
        // Each bit contributes count_set * count_unset * (1 << bit)
        for (int bit = 0; bit < 32; ++bit) {
            long long setCount = bitCount[bit];
            long long unsetCount = n - setCount;
            total += setCount * unsetCount * (1LL << bit);
        }
        return total;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> tokens;
    int value;
    while (cin >> value) {
        tokens.push_back(value);
    }
    if (tokens.empty()) {
        return 0;
    }

    vector<int> arr;
    if (tokens.size() > 1 && tokens[0] == static_cast<int>(tokens.size() - 1)) {
        arr.assign(tokens.begin() + 1, tokens.end());
    } else {
        arr = tokens;
    }

    Solution solution;
    cout << solution.sumXOR(arr);
    return 0;
}
