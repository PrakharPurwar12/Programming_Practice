#include<iostream>
using namespace std;

int main(){

    int n = 5;
   
    while(n!=0){
        int rem = n%2;
        cout<<rem<<" ";
        n /= 2;
    }
    return 0;
}