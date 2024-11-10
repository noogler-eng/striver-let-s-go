// Rotate Matrix by 90 deg
#include<iostream>
#include<vector>
using namespace std;

// rotate a matrix by 90 
// brute-force
// time complexity o(n*n)
vector<vector<int>> rotate_matrix(vector<vector<int>> arr){
    vector<vector<int>> temp(arr.size(), vector<int>(arr[0].size()));
    int n = arr[0].size()-1;
    // all rows are converted to colm
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            temp[j][n - i] = arr[i][j];
        }
    }
    return temp;
}

// optimized version
// - transpse and then reverse
// time complexity o(n*n)
// space compelxity O(1)
void rotate_matrix_o(vector<vector<int>> &arr){
    // transpose
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            arr[i][j] = arr[j][i];
        }
    }

    // reverse each row
    for(int i=0; i<arr.size(); i++){
        int start = 0;
        int end = arr.size()-1;
        while(start <= end){
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
}



void print(vector<vector<int>> arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> temp = rotate_matrix(arr);
    print(temp);
    rotate_matrix_o(arr);
    print(temp);
    return 0;
}