// Job Sequencing Problem
// input: arr[]: {{4, 40}, {1, 10}, {1, 40}, {1, 30}}
// output: 100

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
    int maxDeadline = 0;
    for(int i=0; i<arr.size(); i++) maxDeadline = max(maxDeadline, arr[i].first);

    // here maxDeadline will be comes
    vector<int> temp(maxDeadline, -1);
    int count = 0;
    sort(arr.begin(), arr.end(), [](pair<int, int> &x, pair<int, int> &y){
        return x.second > y.second;
    }); // on based on profit, desceding order of sorting
    for(int i=0; i<arr.size(); i++){
        int deadline = arr[i].first;
        if(temp[deadline-1] == -1){
            temp[deadline-1] = 1;
            count+=arr[i].second;
        }else{
            // now previously which ever day is empty we fill it by job
            for(int j=deadline-2; j>=0; j--){
                if(temp[j] == -1){
                    temp[j] = 1;
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