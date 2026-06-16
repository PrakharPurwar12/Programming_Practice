class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char ch : s){
            if(ch>='a' && ch<='z'){
                res.push_back(ch);
            }else if(ch == '*'){
                if(!res.empty()){
                    res.pop_back();
                }
            }else if(ch == '#'){
                res += res;
            }else if(ch == '%'){
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};