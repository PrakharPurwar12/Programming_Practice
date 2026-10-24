#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j<=n; j++){
    //         cout << n-j+1<<" ";
    //     }
    //     cout<<endl;
    // }
    // int count = 1;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<< count<<" ";
    //         count++;
    //     }
    //     cout << endl;
    // }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout<<"*";
        }
        cout << endl;
    }
    return 0;
}