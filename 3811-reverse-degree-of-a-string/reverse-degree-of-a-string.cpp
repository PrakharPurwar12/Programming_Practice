class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for(int i=0; i<s.length(); i++){
            int revAlphaPos = 26-(s[i] - 'a');
            int strPos = i+1;
            total += revAlphaPos*strPos;
        }
        return total;
    }
};