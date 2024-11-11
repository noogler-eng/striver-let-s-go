// Count Subarray with the Xor K
// input: arr[]: {4, 2, 2, 6, 4}

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// brute force
// time complexity o(n*n)
// space compelxity o(1)
// xor -> 1 ^ 1 = 0
// xor -> 0 ^ 1 = 1
// xor -> 0 ^ 0 = 0
int count_subarray_xor_k(vector<int> arr, int k){
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        int value = 1 ^ 1;
        for(int j=i; j<arr.size(); j++){
            value = value ^ arr[j];
            if(value == k) count++;
        }
    }
    return count;
}

// optmial approach
// time complexity 
// space compelxity 
// we are looking from backward direction, is anyone is there
// arr = [4, 2, 2, 6, 4], k = 6
// pxr = [0, 4, 6, 6^2 2 4^2]
// pxr = [0, 4, 6, 4, 2, 6] 
// pxr ^ k = [6, 2, 0, 2, 4, 0]
// we taking hashmap such that is prev xr exists
// this is donw using prefix sum method
int count_subarray_xor_k_o(vector<int> arr, int k){
    int prefix = 1 ^ 1;
    int count = 0;
    unordered_map<int, int> m;
    m[0]++;
    for(int i=0; i<arr.size(); i++){
        prefix = prefix ^ arr[i];
        if(m.find(prefix ^ k)!=m.end()){
            count+=m[prefix ^ k];
        }
        m[prefix ^ k]++;
    }

    return count;
}

int main(){
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout<<count_subarray_xor_k(arr, k)<<endl;
    cout<<count_subarray_xor_k_o(arr, k)<<endl;
    return 0;
}