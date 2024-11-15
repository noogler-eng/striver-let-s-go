// Sum of Subarray minimums

#include<iostream>
#include<vector>
using namespace std;

// brute force
// time complexity o(n*n)
// space complexity o(1)
int sum_of_subaaray_minimum(vector<int> arr){
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        int mini = INT_MAX;
        for(int j=i; j<arr.size(); j++){
            if(mini > arr[j]) mini = arr[j];
            sum+=mini;
        }
    }
    return sum;
}


// we hace to sum of all the minimums of all the subarrays
int sum_of_subaaray_minimum_o(vector<int> arr){
    
    stack<int> st;
    vector<int> arrLeft(arr.size());
    vector<int> arrRight(arr.size());

    // time complexity o(2n)
    // space complexity o(n)
    // left minimum subarray
    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if(st.empty()) arrLeft[i] = 0;
        else arrLeft[i] = st.top();
        st.push(i);
    }

    // time compelxity o(2n)
    // space complexity o(n)
    // right minimum subarray
    for(int i=arr.size()-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if(st.empty()) arrRight[i] = arr.size();
        else arrRight[i] = st.top();
        st.push(i);
    }
    
    int sum = 0;
    // time compelxity o(n)
    // space complexity o(1)
    for(int i=0; i<arr.size(); i++){
        int noOfTimeMini = (arrLeft[i] - i) * (i - arrRight[i]);
        sum+=noOfTimeMini * arr[i];
    }
    return sum;
}   

int main(){
    vector<int> arr = {3,1,2,4};
    cout<<sum_of_subaaray_minimum(arr)<<endl;
    return 0;
}   