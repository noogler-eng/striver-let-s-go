// distribute the candies
#include<iostream>
#include<vector>
using namespace std;

// time complexity o(n)
// space complexity o(1)
vector<int> distribute_candy(int noOfCandy, int noOfPersons){
    vector<int> candyToPerons(noOfPersons, 0);
    int i=1, n = noOfPersons;
    while(noOfCandy > 0){
        if(noOfCandy < i){
            candyToPerons[((i-1) % n)] += noOfCandy;
            noOfCandy = 0;
        }else{
            candyToPerons[((i-1) % n)] += i;
            noOfCandy = noOfCandy - i;
        }
        i++;
    }
    return candyToPerons;
}

void print(vector<int> arr){
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<endl;
    return;
}

int main(){
    vector<int> ans = distribute_candy(7, 4);
    print(ans);
    return 0;
}