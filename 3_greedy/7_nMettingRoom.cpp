// N Metting Room in Single Room
// input: start[]: {0, 3, 1, 5, 5, 8}
// input: end[]: {5, 4, 2, 9, 7, 9}

#include<iostream>
#include<vector>
using namespace std;

void printHeavy(vector<pair<pair<int, int>, int>> p){
    for(int i=0; i<p.size(); i++){
        cout<<p[i].first.first<<" "<<p[i].first.second<<endl;
    }
    cout<<endl;
}

void print(vector<int> seq){
    for(auto i: seq) cout<<i<<" ";
    cout<<endl;
}


// greedy approach
// time complexity o(2n + nlogn)
// space complexity o(n)
// perform the shorter metting, sort on the basis of the short end time
int no_of_metting_can_take_place(vector<int> start, vector<int> end){
    vector<pair<pair<int, int>, int>> p;
    for(int i=0; i<start.size(); i++) p.push_back({{start[i], end[i]}, i});
    sort(p.begin(), p.end(), [](pair<pair<int, int>, int> &x, pair<pair<int, int>, int> &y){
        return x.first.second - x.first.first < y.first.second - y.first.first;
    });

    printHeavy(p);

    int mettingCount = 0;
    int currentEndTime = 0;
    vector<int> seq;

    for(int i=0; i<p.size(); i++){
        if(p[i].first.first > currentEndTime) {
            mettingCount++;
            seq.push_back(p[i].second);
            currentEndTime = p[i].first.second;
        }
    }

    print(seq);
    return mettingCount;
}


int main(){
    vector<int> start = {0, 3, 1, 5, 5, 8};
    vector<int> end = {5, 4, 2, 9, 7, 9};
    cout<<no_of_metting_can_take_place(start, end)<<endl;
    return 0;
}