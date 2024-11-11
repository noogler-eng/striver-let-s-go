// Find the Beautiful Indices in gaiven array - 2
// KMP alorithm - longest suffix mathees the preifix until that point
// to math two different string we will conect both string then apply kmp
// connect both string
// spply KMP algo

#include<iostream>
using namespace std;

// brute force
// time complexity o(n*n)
// space complexity o(1)
bool compare_both_string(string s, string a){
    for(int i=0; i<=s.length() - a.length(); i++){
        int j=0;
        for(j=0;j<a.length(); j++){
            if(s[i+j]!=a[j]) break;
        }
        if(j == a.length()) return true;
    }
    return false;
}


// KMP algo, optimized approach


// this may be wrong in many cases
// optimized approach
// time compexity o(n)
// space complexity o(1)
// s:abxabcabcaby
// a:abcaby
bool compare_both_string_o(string s, string a){
    int i=0, j=0;
    while(i<s.length()){
        if(s[i] == s[j]){
            i++;
            j++;
            if(j == s.length()) return true;
        }else{
            i++;
            j = 0;
        }
    } 
    return false;
}

int main(){
    string s = "abxabc";
    string a = "abc";
    cout<<compare_both_string(s, a)<<endl;
    cout<<compare_both_string_o(s, a)<<endl;
    return 0;
}
