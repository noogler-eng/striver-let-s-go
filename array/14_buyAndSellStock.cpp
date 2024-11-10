// Buy and Sell Stock - 1
// input: arr[]: {7, 1, 5, 3, 6, 4}

#include<iostream>
#include<vector>
using namespace std;

// optmized approach
// time complexity o(n)
// space complexity o(1)
int buy_and_sell_stock(vector<int> arr){
    int profit = INT_MIN;
    int mini = arr[0];
    for(int i=1; i<arr.size(); i++){
        profit = max(profit, arr[i] - mini);
        mini = min(mini, arr[i]);
    }
    return profit;
}

int main(){
    vector<int> arr = {3, 1, 2};
    cout<<buy_and_sell_stock(arr)<<endl;
    return 0;
}