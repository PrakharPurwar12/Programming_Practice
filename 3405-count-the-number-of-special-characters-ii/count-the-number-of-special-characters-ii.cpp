class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, -1);
        
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            
            if (ch >= 'a' && ch <= 'z') {
                // Lowercase ka hamesha LAST occurrence store kiya
                last_lower[ch - 'a'] = i; 
            } 
            else if (ch >= 'A' && ch <= 'Z') {
                // Uppercase ka sirf FIRST occurrence store kiya
                if (first_upper[ch - 'A'] == -1) {
                    first_upper[ch - 'A'] = i;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            // Condition: Dono exist karne chahiye aur last_lower pehle aana chahiye
            if (last_lower[i] != -1 && first_upper[i] != -1) {
                if (last_lower[i] < first_upper[i]) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};