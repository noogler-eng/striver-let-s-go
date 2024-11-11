// Largest Element in an array
// input: arr[]: {5, 4,2,-1,8, 100, 78, -114}

#include<iostream>
#include<vector>
using namespace std;

// single approach
// time complexity o(n)
// space complexity o(1)
int largest_element(vector<int> arr){
    int largest = INT_MIN;
    for(int i=0; i<arr.size(); i++) largest = max(largest, arr[i]);
    return largest;
}

int main(){
    vector<int> arr = {5, 4,2,-1,8, 100, 78, -114};
    cout<<largest_element(arr)<<endl;
    return 0;
}