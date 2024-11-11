// Count Inversions
// arr[]: {5, 3, 2, 4, 1}
// count no of pair where a[i] > a[j] && j > i

#include<iostream>
#include<vector>
using namespace std;

// brute force 
// time complexity o(n * n)
// space compelxity o(1)
int count_inversions(vector<int> arr){
    int count = 0;
    for(int i=0; i<arr.size();i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] > arr[j]) count++;
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
            // counting all the elements, as more elements will combine then more it will be count
            // for single right element we have this no of left greater element
            count+=mid-left+1;
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


void mergeSort(vector<int> &arr, int low, int high, int &count){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid, count);            // breaking into left one
    mergeSort(arr, mid+1, high, count);         // breaking into right one
    merge(arr, low, mid, high, count);          // merging with some calculation both right and left
}       

// optimized approach
// time complexity o(n * log(n)) -> (n * log(n)) 
// space complexity -> o(n)
// performing merge sort, berfore merging we appling condition and count
// on merging we get new elemnt in right side, so no redudancy is there
// taking right side and merging them then merged part will do stuff with right ....
int count_inversions_o(vector<int> arr){
    int count = 0;
    mergeSort(arr, 0, arr.size()-1, count);
    return count;
}

int main(){
    vector<int> arr = {5, 3, 2, 4, 1};
    cout<<count_inversions(arr)<<endl;
    cout<<count_inversions_o(arr)<<endl;
    return 0;
}