// Non Overlapping Intervals
// input: arr[]: {{1, 2}, {2, 3}, {3, 4}, {1, 3}}
// we have to remove interval which are overlapping

#include<iostream>
#include<vector>
using namespace std;

// minimum no of intervals removed
int no_of_interval_removed(vector<pair<int, int>> arr){
    
    sort(arr.begin(), arr.end(), [](pair<int, int> &x, pair<int, int> &y){
        return x.second < y.second;
    });
    
    int count = 0;
    int endOfLastInterval = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i].first >= endOfLastInterval){
            endOfLastInterval = arr[i].second;
        }else{
            count++;
        }
    }
    return count;
}


int main(){
    vector<pair<int, int>> arr = {{1, 2}, {2, 3}, {3, 4}, {-100, -2}, {5, 7}};
    cout<<no_of_interval_removed(arr)<<endl;
    return 0;
}
