#include<iostream>
using namespace std;

bool checkPalindrome(string str){
    int n = str.length();
    int i = 0;
    int j = n-1;
    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    string str = "raceca";
    if(checkPalindrome(str)){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}
