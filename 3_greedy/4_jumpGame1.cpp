// Jump Game 1
// input: arr[]: [2, 3, 1, 0, 4]
// on 0 we can't jump so jumping in a way so that we can reach

#include<iostream>
#include<vector>
using namespace std;

// greedy approach
// time complexity o(n)
// space complexity o(1)
// 2, 3, 1, 0, 4
// 2, 3, 3, 3, 4
bool jump_game(vector<int> arr){
    // we have to go maximum at each index
    int maxiSteps = 1;
    for(int i=0; i<arr.size(); i++){
        maxiSteps--;
        maxiSteps = max(maxiSteps, arr[i]);
        // if we are at last stage
        if(maxiSteps == 0 && i == arr.size()-1) return true;
        if(maxiSteps == 0) return false;
    }

    return true;
}

int main(){
    vector<int> arr = {2, 3, 1, 0, 4};
    cout<<jump_game(arr)<<endl;
    return 0;
}