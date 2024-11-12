// Candy
// input: ratings[]: {1, 3, 2, 1}
// - each child should get atlest one candy
// - children with higher rating should get more candy then its neighbour one 


#include<iostream>
#include<vector>
using namespace std;

// we traverse from left and follow condition
// we traverse from right and follow both condition 
int give_min_candy(vector<int> arr){
    vector<int> help(arr.size());
    // from left traversal
    help[0] = 1;
    for(int i=1; i<arr.size(); i++){
        if(arr[i] > arr[i-1]){
            help[i] = help[i-1]+1;
        }else{
            help[i] = 1;
        }
    }

    // from right traversal
    help[arr.size()-1] = max(help[arr.size()-1], 1);
    for(int i=arr.size()-2; i>=0; i--){
        if(arr[i] > arr[i+1]){
            help[i] = max(help[i], help[i+1]+1);
        }else{
            help[i] = max(1, help[i]);
        }
    }

    int count = 0;
    for(int i=0; i<arr.size(); i++) count+=help[i];
    return count;
}


int main(){
    vector<int> ratings {1, 3, 2, 1};
    int ans = give_min_candy(ratings);
    cout<<ans<<endl;
    return 0;
}