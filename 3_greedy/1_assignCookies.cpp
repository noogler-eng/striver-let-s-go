// Assign Cookies
// childrens greed: arr[]: {1, 5, 3, 3, 4}
// chocklate packets: arr[]: {4, 2, 1, 2, 1, 3}

#include<iostream>
#include<vector>
using namespace std;

// greedy approach
// time complexity o(m + n)
// space complexity o(1)
int assign_cookies(vector<int> greed, vector<int> cookies){
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    int i=0, j=0;
    while(i<greed.size() && j<cookies.size()){
        if(cookies[j] > greed[i]){
            j++;
            i++;
        }else{
            j++;
        }
    }

    return i+1;
}

int main(){
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookies = {4, 2, 1, 2, 1, 3};
    cout<<assign_cookies(greed, cookies)<<endl;
    return 0;
}