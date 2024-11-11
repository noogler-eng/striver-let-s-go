// Job Sequencing Problem
// input: arr[]: {}

#include<iostream>
#include<vector>
using namespace std;

// id  deadline  profit
// 1     4         40
// 2     1         10
// 3     1         40
// 4     1         30
// sort according to the min deadline and max profit
int maximize_profit(vector<pair<int, int>> arr){
    vector<int> temp(arr.size(), -1);
    int count = 0;
    sort(arr.begin(), arr.end()); // on based on profit
    for(int i=0; i<arr.size(); i++){
        int deadline = arr[i].first;
        if(temp[deadline-1] == -1){
            temp[deadline-1] = arr[i].second;
            count+=arr[i].second;
        }else{
            for(int i=0; i<deadline-1; i++){
                if(temp[i] == -1){
                    temp[i] = arr[i].second;
                    count+=arr[i].second;
                }
            }
        }
    }
    return count;
}

int main(){
    vector<pair<int, int>> arr = {{4, 40}, {1, 10}, {1, 40}, {1, 30}};
    cout<<maximize_profit(arr)<<endl;
    return 0;
}