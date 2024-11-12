// Insert Intervals
// intervals: arr[] = [[1, 3], [6, 9]];
// new interval: [2, 5]

#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> interval){
    for(int i=0; i<interval.size(); i++){
        for(int j = 0; j<interval[i].size(); j++){
            cout<<interval[i][j]<<" ";
        }
        cout<<endl;
    }
}

// they already gives the interval in sorted order
// time complexity o(n)
// space complexity o(n)
vector<vector<int>> insert_interval(vector<vector<int>> &interval, vector<int> new_interval){

    int lastIntervalEndsAt = 0;
    int newIntervalStart = new_interval[0];
    int i = 0;
    vector<vector<int>> res;
    while(i < interval.size() && interval[i][1] < new_interval[0]){
        res.push_back(interval[i]);
        i++;
    }

    while(i < interval.size() && interval[i][0] <= new_interval[1]){
        new_interval[0] = min(new_interval[0], interval[i][0]);
        new_interval[1] = max(new_interval[1], interval[i][1]);
        i++;
    } 
    res.push_back(new_interval);

    while(i < interval.size() && interval[i][0] >= new_interval[1]){
        res.push_back(interval[i]);
        i++;
    }

    return res;
}   

int main(){
    vector<vector<int>> interval = {{1, 3}, {6, 9}};
    vector<int> new_interval = {2, 5};
    vector<vector<int>> ans = insert_interval(interval, new_interval);
    print(ans);
    return 0;
}