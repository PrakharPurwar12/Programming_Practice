class Solution {
    int n_nodes;
    vector<vector<int>> adj;
    vector<int> depth, parent_node, head, heavy, pos;
    vector<int> tree_val;
    int cur_pos;

    int dfs(int u, int p, int d) {
        depth[u] = d;
        parent_node[u] = p;
        int size = 1, max_c_size = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int c_size = dfs(v, u, d + 1);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent_node[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
    }

    struct SegmentTree {
        int n;
        vector<int> tree;
        SegmentTree(int n) : n(n), tree(4 * n, 0) {}
        void update(int node, int start, int end, int idx, int val) {
            if (start == end) {
                tree[node] = val;
                return;
            }
            int mid = (start + end) / 2;
            if (idx <= mid) update(2 * node, start, mid, idx, val);
            else update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) return 0;
            if (l <= start && end <= r) return tree[node];
            int mid = (start + end) / 2;
            return query(2 * node, start, mid, l, r) ^ query(2 * node + 1, mid + 1, end, l, r);
        }
    };

    int query_path(int u, int v, SegmentTree& st) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                res ^= st.query(1, 0, n_nodes - 1, pos[head[u]], pos[u]);
                u = parent_node[head[u]];
            } else {
                res ^= st.query(1, 0, n_nodes - 1, pos[head[v]], pos[v]);
                v = parent_node[head[v]];
            }
        }
        if (depth[u] > depth[v]) {
            res ^= st.query(1, 0, n_nodes - 1, pos[v], pos[u]);
        } else {
            res ^= st.query(1, 0, n_nodes - 1, pos[u], pos[v]);
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n_nodes = n;
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        depth.assign(n, 0);
        parent_node.assign(n, 0);
        head.assign(n, 0);
        heavy.assign(n, -1);
        pos.assign(n, 0);
        cur_pos = 0;

        dfs(0, -1, 0);
        decompose(0, 0);

        SegmentTree st(n);
        tree_val.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            tree_val[i] = mask;
            st.update(1, 0, n - 1, pos[i], mask);
        }

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int mask = 1 << (c - 'a');
                tree_val[u] = mask;
                st.update(1, 0, n - 1, pos[u], mask);
            } else {
                int u, v;
                ss >> u >> v;
                int mask = query_path(u, v, st);
                if ((mask & (mask - 1)) == 0) {
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};