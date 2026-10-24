#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string str){
    for(int i = 0; i < str.length(); i++) {
       str[i] = tolower(str[i]);
    }
    
    int n = str.length();
    int i = 0;
    int j = n-1;
    while(i < j){

        while(str[i]==' ') i++;
        while(str[j]==' ') j--;
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    string str = "  a";
    if(checkPalindrome(str)){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}
