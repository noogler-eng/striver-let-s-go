// Max Xonsucutive Ones
// input: arr[]: {1, 1, 0, 1, 1, 1, 0, 1, 1}

#include<iostream>
#include<vector>
using namespace std;

// simple approach
// time xomplexity o(n)
// space complexity o(1)
int max_consecutive_one(vector<int> arr){
    int countMax = 0;
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 1) count++;
        if(arr[i] == 0) count = 0;
        countMax = max(count, countMax);
    }
    return countMax;
}

int main(){
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    cout<<max_consecutive_one(arr)<<endl;
    return 0;
}