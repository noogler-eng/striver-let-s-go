// Merge Two Sorted Array, without using any extra space
// input: arr1[]: {1, 3, 5, 7}, arr2[]: {0, 2, 6, 8, 9}

#include<iostream>
#include<vector>
using namespace std;

// brute force
// taking an extra array and storing the final ans in that by two pointer
// time complexity o(n1 + n2)
// space complexity o(n1 + n2)
vector<int> merge_two_sroted_array(vector<int> arr1, vector<int> arr2){
    int left = 0;
    int leftHigh = arr1.size();
    int right = 0;
    int rightHigh = arr2.size();
    vector<int> temp;

    while(left < leftHigh && right < rightHigh){
        if(arr1[left] <= arr2[right]){
            temp.push_back(arr1[left]);
            left++;
        }else{
            temp.push_back(arr2[right]);
            right++;
        }
    }

    while(left < leftHigh){
        temp.push_back(arr1[left]);
        left++;
    }

    while(right < rightHigh){
        temp.push_back(arr2[right]);
        right++;
    }

    return temp;
}

// optimized approach
// time complexity o(nlogn)*2
// space complexity o(1)
void merge_two_sroted_array_o(vector<int> &arr1, vector<int> &arr2){
    // taking thr bigger one of the first array
    // taking smaller of the second array then swapp 
    int i=arr1.size()-1;
    int j=0;
    while(arr1[i] > arr2[j]){
        swap(arr1[i], arr2[j]);
        i--;
        j++;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}


void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}


int main(){
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    vector<int> ans = merge_two_sroted_array(arr1, arr2);
    print(ans);
    print(arr1);
    print(arr2);
    return 0;
}
