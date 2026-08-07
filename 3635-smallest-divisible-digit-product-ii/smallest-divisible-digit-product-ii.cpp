#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int count2 = 0, count3 = 0, count5 = 0, count7 = 0;
        while (temp % 2 == 0) { count2++; temp /= 2; }
        while (temp % 3 == 0) { count3++; temp /= 3; }
        while (temp % 5 == 0) { count5++; temp /= 5; }
        while (temp % 7 == 0) { count7++; temp /= 7; }

        if (temp > 1) return "-1";

        auto minDigitsNeeded = [](int c2, int c3, int c5, int c7) -> int {
            int d8 = c2 / 3; c2 %= 3;
            int d9 = c3 / 2; c3 %= 2;
            int d4 = c2 / 2; c2 %= 2;
            int d6 = 0;
            if (c2 == 1 && c3 == 1) {
                d6 = 1;
                c2 = 0;
                c3 = 0;
            }
            return d8 + d9 + d4 + d6 + c2 + c3 + c5 + c7;
        };

        int n = num.size();
        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        int first_zero = -1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
            int d = num[i] - '0';
            p2[i + 1] = p2[i];
            p3[i + 1] = p3[i];
            p5[i + 1] = p5[i];
            p7[i + 1] = p7[i];

            int td = d;
            while (td % 2 == 0) { p2[i + 1]++; td /= 2; }
            while (td % 3 == 0) { p3[i + 1]++; td /= 3; }
            while (td % 5 == 0) { p5[i + 1]++; td /= 5; }
            while (td % 7 == 0) { p7[i + 1]++; td /= 7; }
        }

        if (first_zero == -1) {
            if (p2[n] >= count2 && p3[n] >= count3 && p5[n] >= count5 && p7[n] >= count7) {
                return num;
            }
        }

        int max_i = (first_zero == -1) ? n - 1 : first_zero;

        for (int i = max_i; i >= 0; i--) {
            int start_d = (num[i] - '0') + 1;
            for (int d = start_d; d <= 9; d++) {
                int req2 = max(0, count2 - p2[i]);
                int req3 = max(0, count3 - p3[i]);
                int req5 = max(0, count5 - p5[i]);
                int req7 = max(0, count7 - p7[i]);

                int td = d;
                while (td % 2 == 0) { req2--; td /= 2; }
                while (td % 3 == 0) { req3--; td /= 3; }
                while (td % 5 == 0) { req5--; td /= 5; }
                while (td % 7 == 0) { req7--; td /= 7; }
                req2 = max(0, req2);
                req3 = max(0, req3);
                req5 = max(0, req5);
                req7 = max(0, req7);

                int rem_len = n - 1 - i;
                if (minDigitsNeeded(req2, req3, req5, req7) <= rem_len) {
                    string prefix = num.substr(0, i) + to_string(d);
                    string suffix = "";
                    for (int len = rem_len; len >= 1; len--) {
                        for (int next_d = 1; next_d <= 9; next_d++) {
                            int n2 = req2, n3 = req3, n5 = req5, n7 = req7;
                            int td2 = next_d;
                            while (td2 % 2 == 0) { n2--; td2 /= 2; }
                            while (td2 % 3 == 0) { n3--; td2 /= 3; }
                            while (td2 % 5 == 0) { n5--; td2 /= 5; }
                            while (td2 % 7 == 0) { n7--; td2 /= 7; }
                            n2 = max(0, n2);
                            n3 = max(0, n3);
                            n5 = max(0, n5);
                            n7 = max(0, n7);

                            if (minDigitsNeeded(n2, n3, n5, n7) <= len - 1) {
                                suffix += to_string(next_d);
                                req2 = n2; req3 = n3; req5 = n5; req7 = n7;
                                break;
                            }
                        }
                    }
                    return prefix + suffix;
                }
            }
        }

        int req2 = count2, req3 = count3, req5 = count5, req7 = count7;
        int min_len = minDigitsNeeded(req2, req3, req5, req7);
        int target_len = max(n + 1, min_len);

        string suffix = "";
        for (int len = target_len; len >= 1; len--) {
            for (int next_d = 1; next_d <= 9; next_d++) {
                int n2 = req2, n3 = req3, n5 = req5, n7 = req7;
                int td2 = next_d;
                while (td2 % 2 == 0) { n2--; td2 /= 2; }
                while (td2 % 3 == 0) { n3--; td2 /= 3; }
                while (td2 % 5 == 0) { n5--; td2 /= 5; }
                while (td2 % 7 == 0) { n7--; td2 /= 7; }
                n2 = max(0, n2);
                n3 = max(0, n3);
                n5 = max(0, n5);
                n7 = max(0, n7);

                if (minDigitsNeeded(n2, n3, n5, n7) <= len - 1) {
                    suffix += to_string(next_d);
                    req2 = n2; req3 = n3; req5 = n5; req7 = n7;
                    break;
                }
            }
        }

        return suffix;
    }
};