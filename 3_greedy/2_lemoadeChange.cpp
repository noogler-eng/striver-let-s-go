// Lemonade Change
// input: bills: arr[]: {5, 5, 5, 10, 20}

#include<iostream>
#include<vector>
using namespace std;

// greedy approach
// time complexity o(n)
// space complexity o(1)
// we have to return is all coustmeer served
bool bills_server(vector<int> bills){
    int five = 0, ten = 0, twenty = 0;
    int i = 0, count = 0;
    while(i < bills.size()){
        if(bills[i] == 5){
            five++;
            count++;
        }else if(bills[i] == 10){
            if(five > 0){
                ten++;
                five--;
                count++;
            }else {
                return false;
            }
        }else{
            // first i want to remove 10 then we will remove 5 greedy
            if(ten > 0 && five > 0){
                twenty++;
                ten--;
                five--;
                count++;
            }else if(five > 2){
                twenty++;
                five-=3;
                count++;
            }else{
                return false;
            }
        }
        i++;
    }
    return true;
}

int main(){
    vector<int> bills = {5, 5, 5, 10, 20};
    cout<<bills_server(bills)<<endl;
    return 0;
}