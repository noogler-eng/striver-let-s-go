// Reverse Words In string

#include<iostream>
using namespace std;

void reverse(string &s, int start, int end){
    while(start < end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

// time compelxity o(2N)
// space complexity o(1)
void reverse_words_in_string(string &s){
    int i = 0, j = 0;
    while (i < s.length()) {
        if (s[i+1] == ' ' || i+1 == s.length()) {
            reverse(s, j, i);
            j = i + 2;
        }
        i++;
    }
}


int main(){
    string s = "Let's take LeetCode contest";
    reverse_words_in_string(s);
    cout<<s<<endl;
    return 0;
}