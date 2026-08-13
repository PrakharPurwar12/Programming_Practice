#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int mx;
    int pref;
    int suff;
    char first_char;
    char last_char;
    int len;
};

class Solution {
    vector<Node> tree;

    void merge(int node, int left, int right) {
        tree[node].first_char = tree[left].first_char;
        tree[node].last_char = tree[right].last_char;
        tree[node].len = tree[left].len + tree[right].len;

        tree[node].pref = tree[left].pref;
        if (tree[left].pref == tree[left].len && tree[left].last_char == tree[right].first_char) {
            tree[node].pref += tree[right].pref;
        }

        tree[node].suff = tree[right].suff;
        if (tree[right].suff == tree[right].len && tree[right].first_char == tree[left].last_char) {
            tree[node].suff += tree[left].suff;
        }

        tree[node].mx = max(tree[left].mx, tree[right].mx);
        if (tree[left].last_char == tree[right].first_char) {
            tree[node].mx = max(tree[node].mx, tree[left].suff + tree[right].pref);
        }
    }

    void build(int node, int l, int r, const string& s) {
        if (l == r) {
            tree[node] = {1, 1, 1, s[l], s[l], 1};
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);
        merge(node, 2 * node, 2 * node + 1);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, r, idx, ch);
        }
        merge(node, 2 * node, 2 * node + 1);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);

        int k = queryIndices.size();
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].mx;
        }
        return ans;
    }
};