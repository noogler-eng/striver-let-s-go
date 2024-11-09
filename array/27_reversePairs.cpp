// Reverse the Pairs 
// arr[]: {40, 25, 19, 12, 9, 6, 2}
// ans = no of pairs_exists
// for revserse pair i < j  and arr[i] > 2 * arr[j]

#include<iostream>
#include<vector>
using namespace std;

// brute force
// time complexity o(n * n)
// space complexity o(1)
int no_of_reverse_pairs(vector<int> arr){
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] > 2 * arr[j]) count++;
        }
    }
    return count;
}


void merge(vector<int> &arr, int low, int mid, int high, int &count){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left < mid+1 && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<mid+1){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void countPairs(vector<int> &arr, int low, int mid, int high, int &count){
    int right = mid+1;
    for(int i=low; i<mid+1; i++){
        while(right<=high && arr[i] > 2 * arr[right]){
            right++;
        }
        count+=(right - (mid+1));
    }
}

void mergeSort(vector<int> &arr, int low, int high, int &count){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid, count);            // breaking into left one
    mergeSort(arr, mid+1, high, count);         // breaking into right one
    countPairs(arr, low, mid, high, count);
    merge(arr, low, mid, high, count);          // merging with some calculation both right and left
}       

// optimized approach
// time complexity o(n * log(n) * (n1 + n2)) -> 2(n * log(n)) 
// space complexity -> o(n)
// performing merge sort, berfore merging we appling condition and count
// on merging we get new elemnt in right side, so no redudancy is there
int no_of_reverse_pairs_o(vector<int> arr){
    int count = 0;
    mergeSort(arr, 0, arr.size()-1, count);
    return count;
}


int main(){
    vector<int> arr = {40, 25, 19, 9, 6, 2};
    cout<<no_of_reverse_pairs(arr)<<endl;
    cout<<no_of_reverse_pairs_o(arr)<<endl;
    return 0;
}   

