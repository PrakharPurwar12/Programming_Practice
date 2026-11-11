class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;
        
        if (cb > c1 + c2) {
            cb = c1 + c2;
        }
        
        long long ans = 0;
        
        if (c1 + c2 <= cb) {
            ans = n1 * c1 + n2 * c2;
        } else if (c1 <= c2) {
            if (n1 >= n2) {
                ans += n2 * cb;
                n1 -= n2;
                ans += n1 * min(c1, cb);
            } else {
                ans += n1 * cb;
                n2 -= n1;
                ans += n2 * min(c2, cb);
            }
        } else {
            if (n1 >= n2) {
                ans += n2 * cb;
                n1 -= n2;
                ans += n1 * min(c1, cb);
            } else {
                ans += n1 * cb;
                n2 -= n1;
                ans += n2 * min(c2, cb);
            }
        }
        
        return ans;
    }
};