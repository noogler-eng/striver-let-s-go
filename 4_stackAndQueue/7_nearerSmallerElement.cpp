// Nearest Smallest Element
// we have to tell the nearest smallest element on the left

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    return;
}

// arr[]: [4, 5, 2, 10, 8]
// output: [-1, 4, 4, 2, 2]
// time compelexity o(2n)
// space compelexity o(n)
void nearest_smallest_element(vector<int> &arr){
    stack<int> st;
    for(int i=0; i<arr.size(); i++){
        int temp = arr[i];
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        if(st.empty()) arr[i] = -1;
        else arr[i] = st.top();
        st.push(temp);
    }
}

int main(){
    vector<int> arr = {4, 5, 2, 10, 8};
    nearest_smallest_element(arr);
    print(arr);
    return 0;
}