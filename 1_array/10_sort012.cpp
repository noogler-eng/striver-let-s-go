// Sort the array According to 0s, 1s, and 2s
// input: arr[]: {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1}

#include<iostream>
#include<vector>
using namespace std;

// optmized approach
// time complexity o(n)
// space complexity o(1)
void sort_acc_0_1_2(vector<int> &arr){
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    sort_acc_0_1_2(arr);
    print(arr);
    return 0;
}