// 1. Adjacent Increasing Subarrays detection - 1
//input: arr[]={2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, k = 3

#include<iostream>
#include<vector>
using namespace std;

// - storing 1 if it is greater then prev otherwise 0
// time complexity o(n)
// space complexity o(n)
bool is_increasing_adj_subarray(vector<int> arr, int k){
    // always mark 0, 1 in finding of subarray with increasing or decreasing
    // used prefix then always solution comes
    vector<int> prefix(arr.size(), 0);
    for(int i=1; i<arr.size(); i++){   
        prefix[i] = prefix[i-1] + (arr[i] > arr[i-1] ? 1: 0);
    }

    for(int i=k-1; i<prefix.size()-k; i++){
        if(prefix[i] - prefix[i-k+1] == k-1 && prefix[i+k] - prefix[i+1] == k-1){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {5,8,-2,-1};
    int k = 2;
    cout<<is_increasing_adj_subarray(arr, k)<<endl;
    return 0;
}   