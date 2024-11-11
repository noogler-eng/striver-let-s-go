// Longest Subarray with Sum K

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// brute force
// making all the subarrays and checking for sum, if sum == k then taking max into maxLen
// time complexity o(n*n)
// space complexity o(1)

// optmized apprach
// approach of sliding window
// time complexity o(n)
// space complexity o(1)
int longest_subarray_length_k(vector<int> arr, int k){
    int i=0, j=0, sum=0, maxLen = 0;
    while(j<arr.size()){
        sum+=arr[i];
        if(sum > k){
            sum-=arr[i];
            i++;
        }   
        if(sum == k){
            maxLen = max(maxLen, j-i+1);
        }
        j++;
    }
    return maxLen;
} 

// prefix sum appraoch
// time compleixty o(n)
// space complexity o(n)
int longest_subarray_length_k_ps(vector<int> arr, int k){
    unordered_map<int, int> m;
    int maxLen = 0, prefix = 0;
    m[0] = 0;
    for(int i=0; i<arr.size(); i++){
        prefix += arr[i];
        if(m.find(prefix - k)!=m.end()){
            maxLen = max(i-m[prefix - k], maxLen);
        }
        // if element is present then we want to look the backest element
        if(m.find(prefix) == m.end()){
            m[prefix] = i;
        }
    }
    return maxLen;
} 

int main(){
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k = 3;
    cout<<longest_subarray_length_k(arr, k)<<endl;
    cout<<longest_subarray_length_k_ps(arr, k)<<endl;
    return 0;
}
