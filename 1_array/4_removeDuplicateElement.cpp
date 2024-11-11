// Remove Duplicates From sorted array
#include<iostream>
#include<vector>
using namespace std;

// simple approach
// time xomplexity o(n)
// space complexity o(1)
// after removing the duplicates put anything there
void remove_duplicates_element( vector<int> &arr){
    int prev = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i] == prev) arr[i] = -1;
        else{
            prev = arr[i];
        }
    }

    int i=0, j=0;
    while(j<arr.size()){
        if(arr[j] != -1){
            swap(arr[j], arr[i]);
            i++;
        }
        j++;
    }
}       

void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
    remove_duplicates_element(arr);
    print(arr);
    return 0;
}