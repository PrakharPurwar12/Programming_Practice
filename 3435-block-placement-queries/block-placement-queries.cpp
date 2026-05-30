#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; 
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

    public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        n = max_x + 1;
        tree.assign(4 * n, 0);

        set<int> obstacles;
        obstacles.insert(0);
        
        vector<bool> results;

        for (const auto& q : queries) {
            int type = q[0];
            
            if (type == 1) {
                int x = q[1];
                
                auto it = obstacles.upper_bound(x);
                int next_obs = (it != obstacles.end()) ? *it : -1;
                int prev_obs = *prev(it);

                obstacles.insert(x);

                update(1, 0, n - 1, x, x - prev_obs);

                if (next_obs != -1) {
                    update(1, 0, n - 1, next_obs, next_obs - x);
                }
                
            } else {
                int x = q[1];
                int sz = q[2];

                int max_gap = query(1, 0, n - 1, 0, x);


                auto it = obstacles.upper_bound(x);
                int last_obs_before_x = *prev(it);
                max_gap = max(max_gap, x - last_obs_before_x);

                if (max_gap >= sz) {
                    results.push_back(true);
                } else {
                    results.push_back(false);
                }
            }
        }

        return results;
    }
};