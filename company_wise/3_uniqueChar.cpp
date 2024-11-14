// Unique character first Occ in 1 based indexing

#include<iostream>
using namespace std;

// time complexity o(n*n)
// space complexity o(1)
int get_index(string s){
    int index = -1;

    for(int i=0; i<s.length(); i++){
        int index = i;
        int count = 0;
        for(int j=0; j<s.length(); j++){
            if(s[i] == s[j]) count++;
        }
        if(count == 1) return index+1;
    }

    return -1;

}

int main(){
    string s = "hackthegame";
    cout<<get_index(s)<<endl;
    return 0;
}