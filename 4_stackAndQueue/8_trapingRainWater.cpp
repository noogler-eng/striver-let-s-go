// Trapping Rain Water
// input: arr[]: {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}

#include<iostream>
#include<math.h>
#include<stack>
#include<vector>
using namespace std;

// input: arr[]: {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
// time complexity o(n);
// space complexity o(1);
int rain_water_trap(vector<int> arr){
    int left = 0;
    int right = arr.size()-1;
    int left_max = 0, right_max = 0;
    int total_water = 0;
    while(left <= right){
        if(arr[left] <= arr[right]){
            if(arr[left] >= left_max){
                left_max = arr[left];
            }else {
                total_water += left_max - arr[left];
            }
            left++;
        }else{
            if(arr[right] > right_max){
                right_max = arr[right];
            }else{
                total_water += right_max - arr[right];
            }
            right--;
        }
    }
    return total_water;
}

int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_water_trap(arr)<<endl;
    return 0;
}