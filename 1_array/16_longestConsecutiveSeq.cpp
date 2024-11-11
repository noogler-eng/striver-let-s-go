// Longest Consecutive Seq
// input: arr[]: {102, 4, 100, 1, 101, 3, 2, 1, 1}

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// better solution
// time complexity o(nlogn + n)
// space complexity o(1)
int longestCommonSeq(vector<int> arr){
    sort(arr.begin(), arr.end());
    int countMax = 1;
    int count = 1;
    for(int i=1; i<arr.size(); i++){
        if(arr[i]-1 == arr[i-1]){
            count++;
            countMax = max(count, countMax); 
        }if(arr[i] == arr[i-1]){
            // when both elemt are same we have to do nothing
            continue;
        }else{
            count = 1;
        }
    }
    return countMax;
}

int main(){
    vector<int> arr = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};
    cout<<longestCommonSeq(arr)<<endl;
    return 0;
}