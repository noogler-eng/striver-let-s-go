// Jump Game 2
// we have to find the minimum no of jumps
// input: arr[]: {2, 3, 1, 4, 1, 1, 1, 2}

#include<iostream>
#include<vector>
using namespace std;

// greedy
// important question
// 2, 3, 1, 4, 1, 1, 1, 2
// 2, 3, ..... always takes maximum one
// here there will be no 0, we always gets to end
int min_no_of_jump(vector<int> arr){
    int maxJump = 0;
    int nextJump = 0;
    int countJumps = 0;
    if (arr.size() == 1) return 0;
    for(int i=0; i<arr.size()-1; i++){
        nextJump = max(i + arr[i], nextJump);
        if(i == maxJump){
            countJumps++;
            maxJump = nextJump;
            if(maxJump >= arr.size()-1){
                return countJumps;
            }
        }
    }
    return countJumps;
} 

int main(){
    vector<int> arr = {2, 3, 1, 4, 1, 1, 1, 2};
    cout<<min_no_of_jump(arr)<<endl;
    return 0;
}