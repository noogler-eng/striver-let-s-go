// Shortest Job First
// input: arr[]: 
// algorithm that takes the jobs which has minimum execution time

#include<iostream>
#include<vector>
using namespace std;

// we have to fing the average waiting time
// time complexity o(n)
// space complexity o(1)
int shortest_job_first(vector<int> executionTime){
    sort(executionTime.begin(), executionTime.end());
    int waiting_time = 0;
    int total_time = 0;
    
    // 1, 2, 3, 4, 7
    // 0, 1, 3, 6, 10
    // sum = 0 + 1 + 3 + 6 + 10 = 20 / 5
    for(int i=1; i<executionTime.size(); i++){
        waiting_time = (executionTime[i-1] + waiting_time);
        total_time += waiting_time;
    }
    return total_time / executionTime.size();
}

int main(){
    vector<int> executionTime = {4, 3, 7, 1, 2};
    cout<<shortest_job_first(executionTime)<<endl;
    return 0;
}