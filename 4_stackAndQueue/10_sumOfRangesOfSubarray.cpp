// Sum of Ranges of Subarray
#include<iostream>
#include<stack>
#include<math.h>
#include<vector>
using namespace std;

// brute force
// time complexity o(N*N)
// space compexlity o(1)
int get_sum_of_ranges_of_all_subarrays(vector<int> arr){
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        int mini = INT_MAX, maxi = INT_MIN;
        for(int j=i; j<arr.size(); j++){
            mini = min(mini, arr[j]);
            maxi = max(maxi, arr[j]);
            sum+= maxi - mini; 
        }
    }
    return sum;
}

// gives the sum of the maximum
// time complexity o(3N)
// space complexity o(3N)
int sum_of_subarray_maximum(vector<int> arr){
    stack<int> st;
    vector<int> leftMaxElements(arr.size());
    vector<int> rightMaxElements(arr.size());
    
    // leftMinElements
    for(int i=0; i < arr.size(); i++){
        while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
        if(st.empty()) leftMaxElements[i] = i+1;
        else leftMaxElements[i] = i - st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();

    // rightMinElements
    for(int i=arr.size()-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
        if(st.empty()) rightMaxElements[i] = arr.size()-i;
        else rightMaxElements[i] = st.top() - i;
        st.push(i);
    }

    int sumMini = 0;
    for(int i=0; i<arr.size(); i++){
        sumMini = sumMini + (leftMaxElements[i] * rightMaxElements[i] * arr[i]);
    }
    return sumMini;
}

// gives the sum of all minimum
// time complexity o(3N)
// space complexity o(3N)
int sum_of_subarray_minimum(vector<int> arr){
    stack<int> st;
    vector<int> leftMinElements(arr.size());
    vector<int> rightMinElements(arr.size());
    
    // leftMinElements
    for(int i=0; i < arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if(st.empty()) leftMinElements[i] = i+1;
        else leftMinElements[i] = i - st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();

    // rightMinElements
    for(int i=arr.size()-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if(st.empty()) rightMinElements[i] = arr.size()-i;
        else rightMinElements[i] = st.top() - i;
        st.push(i);
    }

    int sumMini = 0;
    for(int i=0; i<arr.size(); i++){
        sumMini = sumMini + (leftMinElements[i] * rightMinElements[i] * arr[i]);
    }
    return sumMini;
}

// optmized version 
// time complexity o(3N)
// space compelxity o(1)
int get_sum_of_ranges_of_all_subarrays_o(vector<int> arr){
    return sum_of_subarray_maximum(arr) - sum_of_subarray_minimum(arr);
}

int main(){
    vector<int> arr = {1, 4, 3, 2};
    cout<<get_sum_of_ranges_of_all_subarrays(arr)<<endl;
    cout<<get_sum_of_ranges_of_all_subarrays_o(arr)<<endl;
    return 0;
}