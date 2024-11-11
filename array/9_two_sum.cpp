// 2 Sum
// input: arr[]: {2, 6, 5, 8, 11}
// target = 14

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// getting the elelemts to make sum possible 
// time complexity o(n)
// space complexity o(1)
pair<int, int> get_element_sum(vector<int> arr, int target){
    pair<int, int> temp;
    sort(arr.begin(), arr.end());

   int start = 0;
   int end = arr.size()-1;
   while(start < end){
    if(arr[start] + arr[end] == target){
        temp.first = arr[start];
        temp.second = arr[end];
        return temp;
    }else if(arr[start] + arr[end] > target){
        end--;
    }else{
        start++;
    }
   }
    return {-1, -1};
}

// getting the indexed of the element to make sum
// here we have to go ith map
// sorted array not match with original arr
// this can only be done using maps
// time complexity o(n)
// space complexity o(n)
pair<int, int> get_index_sum(vector<int> arr, int target){
    pair<int, int> temp;
    unordered_map<int, int> m;
    for(int i=0; i<arr.size(); i++){
        if(m.find(target-arr[i])!=m.end()){
            temp.first = m[target-arr[i]];
            temp.second = i;
            return temp;
        }
        m[arr[i]] = i;
    }
    return {-1, -1};
}

int main(){
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    pair<int, int> temp_1 = get_element_sum(arr, target);
    cout<<temp_1.first<<" "<<temp_1.second<<endl;
    pair<int, int> temp_2 = get_index_sum(arr, target);
    cout<<temp_2.first<<" "<<temp_2.second<<endl;
    return 0;
}