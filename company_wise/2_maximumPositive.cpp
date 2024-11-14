#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}

// prefix sum
// time complexity o(nlogn)
// space complexity o(1)
int maximum_positive(vector<int> arr){
    sort(arr.begin(), arr.end(), [](int x, int y){
        if(x > y) return true;
        return false;
    });
    print(arr);

    int count = 0;
    int pSum = 0;
    for(int i=0; i<arr.size(); i++){
        pSum+=arr[i];
        if(pSum > 0) count++;
    }

    return count;
}

int main(){
    vector<int> arr = {-6, 3, 4, -10};
    cout<<maximum_positive(arr)<<endl;
    return 0;
}