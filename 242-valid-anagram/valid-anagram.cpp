class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char, int>a;
        for(char ch:s){
            a[ch]++;
        }
        for(char ch:t){
            a[ch]--;
        }
        for(auto &p:a){
            if(p.second != 0) return false;
        }
        return true;
        
    }
};