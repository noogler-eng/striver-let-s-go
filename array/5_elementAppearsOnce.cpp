// Element that Appears Once
// input: arr[]: {1, 1, 3, 3, 4, 5, 5, 7, 7}

#include<iostream>
#include<vector>
using namespace std;

// simple approach
// time complexity o(n)
// space complexity o(1)
int ele_repeat_once(vector<int> arr){
    int value = 1 ^ 1;
    for(int i=0; i<arr.size(); i++){
        value = value ^ arr[i];
    }
    return value;
}

int main(){
    vector<int> arr = {1, 1, 3, 3, 4, 5, 5, 7, 7};
    cout<<ele_repeat_once(arr)<<endl;
    return 0;
}
