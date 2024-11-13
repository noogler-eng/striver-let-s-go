// Implement of Min Stack - 1
#include<iostream>
#include<vector>
using namespace std;
// 12, 15, 10 
// min = 10
// top = 10
// 12 15
// min = 12
// top = 15

// time complexity o(n)
// space complexity o(n)
class MinStack{
    public: 
        // taking an pair to store the current value and min value up till now
        vector<pair<int, int>> arr;
        int minUntilNow = INT_MAX;
        void push(int x){
            minUntilNow = min(minUntilNow, x);
            arr.push_back({x, minUntilNow});
        }

        void pop(){
            if(arr.size() <= 0) return;
            arr.pop_back();
            minUntilNow = arr[arr.size()-1].second;
        }

        int top(){
            if(arr.size() <= 0) return -1;
            return arr[arr.size()-1].first;
        }

        int getMin(){
            if(arr.size() <= 0) return -1;
             return arr[arr.size()-1].second;
        }
};

int main(){
    MinStack m;
    m.push(3);
    m.push(4);
    m.push(0);
    m.push(5);
    m.push(2);

    cout<<m.top()<<endl;
    cout<<m.getMin()<<endl;
    m.pop();
    cout<<m.top()<<endl;
    cout<<m.getMin()<<endl;
    return 0;
}