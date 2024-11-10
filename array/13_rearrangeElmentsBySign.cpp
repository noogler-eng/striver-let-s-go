// Rearrange the elements by sign
// input: arr[]: {3, 1, -2, -5, 2, -4}
// arrange in a way so the +, -, +, - ... in same order

#include<iostream>
#include<vector>
using namespace std;

// brute force
// time complexity o(n1 + n2) => o(n)
// space complexity o(n1 + n2) => o(n)
void arrange_element_by_sing(vector<int> &arr){
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] >= 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    int i=0, j=0, k=0;
    while(i < pos.size() && j < neg.size() ){
        arr[k] = pos[i];
        k++;
        arr[k] = neg[j];
        k++;
        
        i++;
        j++;
    }

    while(i < pos.size()){
        arr[k] = pos[i];
        k++;
        i++;
    }

    while(j < neg.size()){
        arr[k] = neg[j];
        j++;
        k++;
    }
}

void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    arrange_element_by_sing(arr);
    print(arr);
    return 0;
}