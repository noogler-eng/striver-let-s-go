// Next Greater Element - 2
// here we can also look on the circular direction as well

#include<iostream>
using namespace std;

// vector: 2, 10, 12, 1, 11
// we consider [2, 10, 12, 1, 11][2, 10, 12, 1, 11]
// time complexity o(2n)
// space complexity o(2n)
void next_greater_element_2(vector<int> &arr){
    stack<int> st;
    for(int i=0; i<arr.size(); i++) st.push(arr[i]);

    for(int i=arr.size()-1; i>=0; i--){
        int temp = arr[i];
        while(!st.empty() && arr[i] >= st.top()) st.pop();
        if(st.empty()) arr[i] = -1;
        else arr[i] = st.top();
        st.push(temp);
    }
}

void print(vector<int> &arr){
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {2, 10, 12, 1, 11};
    next_greater_element_2(arr);
    print(arr);
    return 0;
}
