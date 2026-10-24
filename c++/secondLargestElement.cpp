#include<iostream>
#include<vector>
using namespace std;

int getsecondLargest(vector<int>& arr){
    int largest = -1, secondLargest = -1;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(secondLargest < arr[i] && arr[i]!= largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){
    vector<int> arr = {1,2,3,4,4,4};

    int secondLargest = getsecondLargest(arr);
    if (secondLargest == -1) {
        cout << "There is no second largest distinct element." << endl;
    } else {
        cout << "Second largest element: " << secondLargest << endl;
    }

    return 0;
}
