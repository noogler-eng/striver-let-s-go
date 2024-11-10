// Majority Element
// input: arr[]: {2, 2, 3, 3, 1, 2, 2}

#include<iostream>
#include<vector>
using namespace std;

// optmized appraoch
// time complexity o(n)
// space complexity o(n)
// here we have to get the element and recheck it 
int majority_element(vector<int> arr){
    int el, count = 0;
    int majority = arr.size()/2;
    vector<int> temp;
    
    int i=0;
    while(i < arr.size()){
        if(count == 0){
            el = arr[i];
            count++;
        }else {
            if(arr[i] == el) {
                count++;
            } else {
                count--;
            }
        }
        i++;
    }

    int reCount = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == el) reCount++;
    }


    if(reCount > majority) return el;
    else return -1; 
} 

int main(){
    vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
    int ans = majority_element(arr);
    cout<<ans<<endl;
    return 0;
}