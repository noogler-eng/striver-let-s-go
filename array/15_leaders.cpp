// Leader of An Array
// everyting on the right should be smaller
// input: arr[]: {10, 22, 12, 3, 0, 6}

#include<iostream>
#include<vector>
using namespace std;

// optmized appraoch
// time complexity o(n)
// space complexity o(1)
vector<int> get_leaders(vector<int> arr){
    int maxi = -1;
    // this maxi index will in case of array contains same elements
    int maxiIndex = -1;
    vector<int> temp;
    for(int i=arr.size()-1; i>=0; i--){
        if(arr[i] > maxi){
            maxi = arr[i];
            maxiIndex = i;
        }
        if(arr[i] == maxi && i == maxiIndex) temp.push_back(maxi);
    }
    return temp;
}

void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    vector<int> ans = get_leaders(arr);
    print(ans);
    return 0;
}