// Balanced Parenthesis
// input: s: "()[{}()]"

#include<iostream>
#include<stack>
using namespace std;

// stack approach
// time complexity o(n)
// space complexity o(n)
bool is_balance(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }else{
            if(st.empty()) return false;
            else{
                if(s[i] == ')' && st.top() == '(' || s[i] == '}' && st.top() == '{' || s[i] == ']' && st.top() == '[') {
                    st.pop();
                    continue;
                }else{
                    return false;
                }
            }
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main(){
    string s = "()[{}()]";
    cout<<is_balance(s)<<endl;
    return 0;
}