// Count Subarray Sum Equals K
// input: arr[]: {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// brute-focre
// time complexity o(n*n)
// space complexity o(1)
int count_no_of_subarray(vector<int> arr, int k){
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i; j<arr.size(); j++){
            sum+=arr[j];
            if(sum == k) count++;
        }
    }
    return count;
}

// optmized approach
// time complexity o(n)
// space complexity o(n)
// using of method prefix sum
// y + k = prefix_sum then we have to count the number of y
int count_no_of_subarray_o(vector<int> arr, int k){
    int prefix = 0, count = 0;
    unordered_map<int, int> m;
    for(int i=0; i<=arr.size(); i++){
        m[prefix]++;
        count+=m[prefix-k];
        prefix = prefix + arr[i];
    }
    return count;
}

// helper function
// using of the sliding window
int sum_k(vector<int> arr, int k){
    int r = 0, i = 0, sum = 0, count = 0;
    while(r < arr.size()){
        sum+=arr[r];
        while(sum > k){
            sum-=arr[i];
            i++;
        }
        count+=(r-i+1);
        r++;
    }
    return count;
}

// time compelxity o(2n)
// space complexity o(1)
// this approach is valid only in poitive cases only
int count_no_of_subarray_ao(vector<int> arr, int k){
    return (sum_k(arr, k) - sum_k(arr, k-1));
}

int main(){ 
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    cout<<count_no_of_subarray(arr, k)<<endl;
    cout<<count_no_of_subarray_o(arr, k)<<endl;
    cout<<count_no_of_subarray_ao(arr, k)<<endl;
    return 0;
}
