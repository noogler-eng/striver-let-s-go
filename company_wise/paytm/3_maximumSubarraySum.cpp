// Maximum Subarray Sum

#include<iostream>
#include<vector>
using namespace std;

// {-2,1,-3,4,-1,2,1,-5,4}
//  0, 1, 0, 4, 3, 5, 6, 1, 5
int max_subarray_sum(vector<int> arr){
    int sum = 0, maxSum = arr[0];  // so it can take atleast one vlaue of subarray
    for(int i=0; i<arr.size(); i++){
        if(sum < 0) sum = 0;
        sum+=arr[i];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}


int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<max_subarray_sum(arr)<<endl;
    return 0;
}