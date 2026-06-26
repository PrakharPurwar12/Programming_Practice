class FenwickTree {
    vector<int> tree;
    int size;
public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }
    void update(int i, int delta) {
        while (i <= size) {
            tree[i] += delta;
            i += i & (-i);
        }
    }
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }
        
        vector<int> ranks = pref;
        sort(ranks.begin(), ranks.end());
        ranks.erase(unique(ranks.begin(), ranks.end()), ranks.end());
        
        auto get_rank = [&](int val) {
            return lower_bound(ranks.begin(), ranks.end(), val) - ranks.begin() + 1;
        };
        
        FenwickTree bit(ranks.size());
        long long ans = 0;
        
        for (int i = 0; i <= n; i++) {
            int r = get_rank(pref[i]);
            ans += bit.query(r - 1);
            bit.update(r, 1);
        }
        
        return ans;
    }
};