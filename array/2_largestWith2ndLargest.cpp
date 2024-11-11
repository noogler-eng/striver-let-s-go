// Largest Element and Second Largest in an array
// input: arr[]: {5, 4,2,-1,8, 100, 78, -114}

#include<iostream>
#include<vector>
using namespace std;

// single approach
// time complexity o(n)
// space complexity o(1)
pair<int, int> largest_element_and_2nd_largest(vector<int> arr){
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }else if(arr[i] > second_largest){
            second_largest = arr[i];
        }else{
            continue;
        }
    }
    return {largest, second_largest};
}

int main(){
    vector<int> arr = {5, 4,2,-1,8, 100, 78, -114};
    pair<int, int> ans = largest_element_and_2nd_largest(arr);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}