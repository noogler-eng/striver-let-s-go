// Merge Overlapping Intervals
// input: arr[]: {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}}

#include<iostream>
#include<vector>
using namespace std;

// brute force 
// time complexity o(nlogn) + o(n)
// space compleixty o(1)
vector<vector<int>> merger_overlapping_intervals(vector<vector<int>> arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> temp;
    temp.push_back(arr[0]);

    for(int i=1; i<arr.size(); i++){
        vector<int> overlap = arr[i];
        vector<int> lastOverlap = temp[temp.size()-1];
        if(overlap[0] > lastOverlap[1]){
            temp.push_back(overlap);
            continue;
        }

        if(lastOverlap[0] < overlap[0] && overlap[1] < lastOverlap[1]){
            continue;
        }

        if(lastOverlap[0] < overlap[0] && overlap[1] > lastOverlap[1]){
            temp[temp.size()-1][1] = overlap[1];
        }
    }

    return temp;
}

void print(vector<vector<int>> arr){
    for(auto i: arr){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    vector<vector<int>> ans = merger_overlapping_intervals(arr);
    print(ans);
}