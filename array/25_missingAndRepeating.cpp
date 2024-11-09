// Missing and Repeating Number From Array
// input: arr[]: {4, 3, 2, 6, 1, 1}, rnage [1, N]

#include<iostream>
#include<vector>
using namespace std;

// brute force
// taking an another arry and traversing array and fill the seen elemtn
// if any element is already filled then it is repeating number

// optmized approach
// time complexity o(n)
// space complexity o(1)
// apprach of making negative if already seen 
pair<int, int> missing_and_repeating_number(vector<int> arr){
    pair<int, int> ans;
    int repeating = -1;
    int missing = -1;

    // repeating founding
    for(int i=0; i<arr.size(); i++){
        if(arr[arr[i]-1] < 0) {
            repeating = arr[i];
            break;
        }
        arr[arr[i]-1] = -arr[arr[i]-1];
    }

    int sumL = 0;
    for(int i=0; i<arr.size(); i++){
        // as whole array becomes negative due to above finging repeating
        sumL+=abs(arr[i]);
    }
    sumL = sumL - repeating;

    missing = ((arr.size() * (arr.size() + 1) / 2) - (sumL));
    ans.first = repeating;
    ans.second = missing;
    return ans;
}

int main(){
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    pair<int, int> ans = missing_and_repeating_number(arr);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}