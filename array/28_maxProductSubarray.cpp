// Maximum Product Subarray
// arr[]: {2, 3, -2, 4}
// ans = 6

// subarray - any continous part of array in same order

#include<iostream>
#include<vector>
using namespace std;

// bruteforce
// time complexity o(n*n)
// space complexity o(1)
// while finding all the subarray we finding maxProduct
int max_product_subarray(vector<int> arr){
    int ans = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        int product = 1;
        for(int j=i; j<arr.size(); j++){
            product = product * arr[j];
            ans = max(ans, product);
        }
    }
    return ans;
}

// optmized version
// time complexity o(n)
// space complexity o(1)
// 
// if array has all positive -> multiply all
// if array has even negatives and other positive -> multiply all
// if array has odd negatives and other posotive -> prefix, suffix
// arr = {3, 2, -1, 4, -6, 3, -2, 6} 
int max_product_subarray_o(vector<int> arr){
    int prefix = 1, siffix = 1;
    int ans = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(prefix == 0) prefix = 1;
        if(siffix == 0) siffix = 1;
        prefix = prefix * arr[i];
        siffix = siffix * arr[arr.size()-i-1];
        ans = max(ans, max(prefix, siffix));
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 2, -1, 4, -6, 3, -2, 6};
    cout<<max_product_subarray(arr)<<endl;
    cout<<max_product_subarray_o(arr)<<endl;
    return 0;
}