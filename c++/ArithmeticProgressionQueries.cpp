#include <bits/stdc++.h>
using namespace std;

class NumArray {
    int n;
    vector<long long> tree;
    vector<long long> lazyBase;
    vector<long long> lazyStep;

    void push(int node, int start, int end) {
        if (lazyBase[node] == 0 && lazyStep[node] == 0) return;

        int mid = (start + end) / 2;
        int leftLen = mid - start + 1;
        int rightLen = end - mid;

        // Apply to left child
        tree[2 * node] += (long long)lazyBase[node] * leftLen + (long long)lazyStep[node] * leftLen * (leftLen - 1) / 2;
        lazyBase[2 * node] += lazyBase[node];
        lazyStep[2 * node] += lazyStep[node];

        // Apply to right child
        long long rightBase = lazyBase[node] + (long long)lazyStep[node] * leftLen;
        tree[2 * node + 1] += (long long)rightBase * rightLen + (long long)lazyStep[node] * rightLen * (rightLen - 1) / 2;
        lazyBase[2 * node + 1] += rightBase;
        lazyStep[2 * node + 1] += lazyStep[node];

        lazyBase[node] = 0;
        lazyStep[node] = 0;
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            int len = end - start + 1;
            long long currentBase = val + (start - l);
            tree[node] += (long long)currentBase * len + (long long)len * (len - 1) / 2;
            lazyBase[node] += currentBase;
            lazyStep[node] += 1;
            return;
        }

        push(node, start, end);
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long querySum(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];

        push(node, start, end);
        int mid = (start + end) / 2;
        return querySum(2 * node, start, mid, l, r) + querySum(2 * node + 1, mid + 1, end, l, r);
    }

public:
    NumArray(vector<int> &arr, int n) {
        this->n = n;
        tree.assign(4 * n + 1, 0);
        lazyBase.assign(4 * n + 1, 0);
        lazyStep.assign(4 * n + 1, 0);
        for (int i = 0; i < n; i++) {
            updateRange(1, 1, n, i + 1, i + 1, arr[i]);
        }
    }

    void update(int l, int r, int val) {
        updateRange(1, 1, n, l, r, val);
    }

    long long rangeSum(int l, int r) {
        return querySum(1, 1, n, l, r);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    NumArray numArray(arr, arr.size());

    cout << "Initial sum [1, 5]: " << numArray.rangeSum(1, 5) << '\n';

    // Apply arithmetic progression update: add 1, 2, 3 to positions 2..4
    numArray.update(2, 4, 1);
    cout << "After update sum [1, 5]: " << numArray.rangeSum(1, 5) << '\n';
    cout << "Range sum [2, 4]: " << numArray.rangeSum(2, 4) << '\n';

    return 0;
}
