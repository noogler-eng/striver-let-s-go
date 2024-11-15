//minimize the cost of array
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

// mimizing
// time complexity o(n)
// space complexity o(1)
int minimze_cost(vector<int> arr){
    // finding the max diff anywhere
    int indexOfMaxDiff = -1;
    int maxDiff = INT_MIN;
    for(int i=1; i<arr.size(); i++){
        int diff = abs(arr[i] - arr[i-1]);
        if(diff > maxDiff){
            maxDiff = diff;
            indexOfMaxDiff = i;
        }
    }

    int avergaeValue = (arr[indexOfMaxDiff] + arr[indexOfMaxDiff-1]) / 2;
    cout<<avergaeValue<<endl;
    int cost = 0;
    for(int i=1; i<arr.size(); i++){
        if(i == indexOfMaxDiff){
            cost += pow(avergaeValue - arr[i-1], 2);
            cost += pow(arr[i] - avergaeValue, 2);
            continue;
        }
        cost+=pow(arr[i] - arr[i-1], 2);
    }

    return cost;

}

int main(){
    vector<int> arr = {1, 3, 5, 2, 10};
    cout<<minimze_cost(arr)<<endl;
    return 0;
}