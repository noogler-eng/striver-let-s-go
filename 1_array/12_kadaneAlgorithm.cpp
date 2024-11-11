// Kadane Algorithm
// input: arr[]: {-2, -3, 4, -1, -2, 1, 5, -3}
// output 7

#include<iostream>
#include<vector>
using namespace std;

// brute force
// toaking all the subarray and finding sum max
// time complexity o(n*n)
// space complexity o(1);


// kadane algorith;
// time complexity o(n);
// space complexity o(1);
int max_sum_subarray_k(vector<int> arr){
    
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
        if(sum < 0) sum = 0;
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

// we can print the first Max subarray
pair<int, int> max_sum_subarray_k_print(vector<int> arr){
    
    int sum = 0;
    int maxSum = INT_MIN;
    int start = -1, end = -1, s = -1;
    for(int i=0; i<arr.size(); i++){
        // whenever sum is 0 we have a new start
        if(sum == 0) s = i;
        sum+=arr[i];
        if(sum < 0) sum = 0;
        if(sum > maxSum){
            maxSum = sum;
            start = s;
            end = i;
        }
    }

    return {start, end};
}

int main(){
    // contains both postive and negative
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<max_sum_subarray_k(arr)<<endl;
    pair<int, int> ans = max_sum_subarray_k_print(arr);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}