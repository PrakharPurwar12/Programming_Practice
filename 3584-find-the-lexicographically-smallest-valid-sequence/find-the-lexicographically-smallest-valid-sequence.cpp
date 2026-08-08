class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> suf(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }
        
        vector<int> res;
        int jj = 0;
        bool used = false;
        
        for (int i = 0; i < n && jj < m; i++) {
            if (word1[i] == word2[jj]) {
                res.push_back(i);
                jj++;
            } else if (!used && suf[i + 1] >= m - jj - 1) {
                used = true;
                res.push_back(i);
                jj++;
            }
        }
        
        if (jj < m) return {};
        return res;
    }
};