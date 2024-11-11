// Check Wheather Array is Sorted or Not
// input: arr[]: {1, 2, 3, 4, 5}

#include<iostream>
#include<vector>
using namespace std;

// simple approach
// time complexity o(n)
// space complexity o(1)
bool check_if_array_is_sorted(vector<int> arr){
    for(int i=1; i<arr.size(); i++) if(arr[i] < arr[i-1]) return false;
    return true;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    cout<<check_if_array_is_sorted(arr)<<endl;
    return 0;
}