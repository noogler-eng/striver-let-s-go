// Minimum No Of Platforms

#include<iostream>
#include<vector>
using namespace std;

// brute force is to finding the intersections 
// no of intersection is minimum no of station required

// sorting acc to minimum deprature time and arrival time
// 900 955  1100 945  1500 1800
// 920 1130 1150 1200 1900 2000
// minimum no of 3 platforms required
int minimum_no_ways(vector<int> arrival, vector<int> departure){
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    // 900 955  945  1100 1500 1800
    // 920 1130 1150 1200 1900 2000
    int countStations = 1;
    int platforms = 1;
    int i = 1;
    int j = 0;
    while(i <= arrival.size()){
        if(arrival[i] > departure[j]){
            i++;
            j++;
        }else{
            countStations++;
            // first clear the prev train then move to next deaprting train
            i++;
        }
        platforms = max(platforms, countStations);
    }
    return platforms;
}

int main(){
    vector<int> arrival = {900, 945, 955, 1100, 1500, 1800};
    vector<int> departure = {920, 1200, 1130, 1150, 1900, 2000};
    cout<<minimum_no_ways(arrival, departure)<<endl;
    return 0;
}