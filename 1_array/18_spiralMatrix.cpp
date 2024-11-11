// Spiral Matrix
// input: arr[][]: 
// 1 2 3 4 5 6
// 20 ......
// .....


#include<iostream>
#include<vector>
using namespace std;

// time complexity o(n*n)
// cpace complexity o(1)
void spiral_form(vector<vector<int>> arr){
    int left = 0, right = arr[0].size()-1, top = 0, bottom = arr.size()-1;
    while(left <= right &&  top <= bottom){
        for(int i=left; i<=right; i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int j=top; j<=bottom; j++){
            cout<<arr[j][right]<<" ";
        }
        right--;

        if(top <= bottom){
            for(int i=right; i>=left; i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }

        if(left <= right){
            for(int j=bottom; j>=top; j--){
                cout<<arr[j][left]<<" ";
            }
            left++;
        }
    }
}

int main(){
    vector<vector<int>> arr = {
        {1, 2, 3, 4, 5, 6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 26, 9}, 
        {17, 30, 29, 28, 27, 10}, 
        {16, 15, 14, 13, 12, 11}
    };

    spiral_form(arr);
    cout<<endl;
    return 0;
}