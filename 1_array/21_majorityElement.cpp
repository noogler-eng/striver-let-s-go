// Majority Element
// input: arr[]: {1, 1, 1, 3, 3, 2, 2, 2}
// number appears more then n / 3 times return

#include<iostream>
#include<math.h>
#include<vector>
#include<unordered_map>
using namespace std;

// brute-force
// time complexity o(n)
// space complexity o(n)
vector<int> majority_element(vector<int> arr){
    int n = arr.size();
    int mojority = floor(n / 3);
    vector<int> temp;
    unordered_map<int, int> m;

    // here at max 2 element can be ans, having 3 each
    for(int i=0; i<n; i++){
        m[arr[i]]++;
        if(m[arr[i]] > mojority) temp.push_back(arr[i]);
    }

    return temp;
}

// optmized approach
// time complexity o(n)
// space complexity o(1)
vector<int> majority_element_o(vector<int> arr){
    int n = arr.size();
    int mojority = floor(n / 3);
    vector<int> temp;

    int cnt_1 = 0, cnt_2 = 0;
    int el_1, el_2;
    for(int i=0; i<n; i++){
        if(cnt_1 == 0 && arr[i]!=el_2){
            cnt_1+=1;
            el_1 = arr[i];
        }else if(el_1 == arr[i]) {
            cnt_1++;
        }else {
            if(cnt_2 == 0 && arr[i]!=el_1){
                cnt_2+=1;
                el_2 = arr[i];
            }else if(el_2 == arr[i]) {
                cnt_2++;
            }else{
                cnt_1--;
                cnt_2--;
            }
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;
    // checking if it is majority one
    for(int i=0; i<n; i++){
        if(el_1 == arr[i]) cnt1++;
        if(el_2 == arr[i]) cnt2++;
    }

    if(cnt1 > mojority) temp.push_back(el_1);
    if(cnt2 > mojority) temp.push_back(el_2);
    return temp;
}


void print(vector<int> arr){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {2, 1, 1, 3, 1, 4, 5, 6};
    vector<int> ans = majority_element(arr);
    vector<int> ans1 = majority_element_o(arr);
    print(ans);
    print(ans1);
    return 0;
}