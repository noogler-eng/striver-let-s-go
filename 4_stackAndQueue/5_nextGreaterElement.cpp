// Next Greater Element
// Monotonic Stack - we use stack to store specific element
// input: arr[]: {6, 0, 8, 1, 3}

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// pointers approach in stack
// time complexity o(n + n)
// space complexity o(n)
void next_greater_element(vector<int> &arr){
    stack<int> st;
    int n = arr.size()-1;
    // for the most right element
    for(int i=n; i>=0; i--){
        int temp = arr[i];
        while(!st.empty() && arr[i] >= st.top()) st.pop();
        if(st.empty()){
            arr[i] = -1;
            st.push(temp);
            continue;
        } 
        arr[i] = st.top();
        if(temp > st.top()) st.push(temp);
    }
}

void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {6, 0, 8, 1, 3};
    next_greater_element(arr);
    print(arr);
    return 0;
}