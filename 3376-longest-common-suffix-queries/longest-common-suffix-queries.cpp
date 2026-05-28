class Solution {
private:
    struct TrieNode {
        int children[26];
        int best_index;
        
        TrieNode() {
            fill(begin(children), end(children), -1);
            best_index = -1;
        }
    };

    vector<TrieNode> trie;

    bool isBetter(int curr_idx, int best_idx, const vector<string>& wordsContainer) {
        if (best_idx == -1) return true;
        if (wordsContainer[curr_idx].length() != wordsContainer[best_idx].length()) {
            return wordsContainer[curr_idx].length() < wordsContainer[best_idx].length();
        }
        return curr_idx < best_idx;
    }

    void insert(const string& word, int word_idx, const vector<string>& wordsContainer) {
        int curr = 0;
        
        if (isBetter(word_idx, trie[curr].best_index, wordsContainer)) {
            trie[curr].best_index = word_idx;
        }

        for (int i = word.length() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if (trie[curr].children[ch] == -1) {
                trie.push_back(TrieNode());
                trie[curr].children[ch] = trie.size() - 1;
            }
            curr = trie[curr].children[ch];
            
            if (isBetter(word_idx, trie[curr].best_index, wordsContainer)) {
                trie[curr].best_index = word_idx;
            }
        }
    }

    int search(const string& query) {
        int curr = 0;
        int last_best = trie[0].best_index;

        for (int i = query.length() - 1; i >= 0; i--) {
            int ch = query[i] - 'a';
            if (trie[curr].children[ch] == -1) {
                break;
            }
            curr = trie[curr].children[ch];
            last_best = trie[curr].best_index;
        }
        return last_best;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        trie.push_back(TrieNode());
        
        int global_best_idx = 0;
        for (int i = 1; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].length() < wordsContainer[global_best_idx].length()) {
                global_best_idx = i;
            }
        }
        trie[0].best_index = global_best_idx;

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& query : wordsQuery) {
            ans.push_back(search(query));
        }

        return ans;
    }
};