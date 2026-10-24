#include<iostream>
#include<algorithm>
using namespace std;

string reverseString(string str){
    int n = str.length();

    reverse(str.begin(),str.end());
    // cout << str <<endl;

    int start = 0;
    
    for(int end = 0; end <=n; end++){
        if(str[end]==' ' || end==n){
            reverse(str.begin()+start,str.begin()+end);

            start = end + 1;
        }
    }
    return str;
}

int main(){
    string str = "I love coding";
    string ans = reverseString(str);
    cout << ans;
    return 0;
}