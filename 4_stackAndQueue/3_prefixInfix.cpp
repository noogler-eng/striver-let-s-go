// Prefix in which operators comes first then argrmnets

#include<iostream>
#include<stack>
using namespace std;

void reverse(string &s){
    int start = 0;
    int end = s.length()-1;
    while(start <= end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

int priority(char s){
    if(s == '^' || s == '%') return 4;
    else if(s == '*' || s == '/') return 3;
    else if(s == '+' || s == '-') return 2;
    else return 1;
}

// 1. reverse the infix
// 2. infix to postfix
// 3. reverse => anser
string infix_to_prefix(string s){
    reverse(s);
    cout<<s<<endl;
    string new_postfix = "";

    stack<char> st;
    st.push('#');
    for(int i=0; i<s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            new_postfix.push_back(s[i]);
        }else if(s[i] == ')'){
            st.push(s[i]);
        }else if(s[i] == '('){
            // as this comes afterward we give priority to part inside () so first take it out
            while (st.top() != '#' && st.top() != ')') {
                new_postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }else{
            while(priority(st.top()) > priority(s[i])){
                new_postfix.push_back(st.top());
                st.pop();
            } 
            st.push(s[i]);
        }
    }

    while(st.top()!='#'){
        new_postfix.push_back(st.top());
        st.pop();
    }
    st.pop();

    reverse(new_postfix);
    return new_postfix;
}

// prefix to infix
// 1. iterating from back
// 2. operands to stack
// 3. operator calulate from stack
// 4. the last one on stack is ans

int main(){
    string s = "(a+b)*c-d+f";
    cout<<infix_to_prefix(s)<<endl;
    return 0;
}