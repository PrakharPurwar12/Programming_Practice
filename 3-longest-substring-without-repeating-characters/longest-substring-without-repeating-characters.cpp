class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastPos(256, -1);
        
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            if (lastPos[currentChar] >= left) {
                left = lastPos[currentChar] + 1;
            }
            
            lastPos[currentChar] = right;
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};