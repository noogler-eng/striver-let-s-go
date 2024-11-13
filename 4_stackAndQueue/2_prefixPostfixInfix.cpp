// Prefix - when operands comes first to its arguments
// Postfix - when operands comes after to its arguments
// Infix - when operands comes in between to its arguments

#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

// folow PEMDAS
int priority(char s){
    if(s == '^' || s == '%') return 4;
    else if(s == '*' || s == '/') return 3;
    else if(s == '+' || s == '-') return 2;
    else return 1;
}

// Infix to Postfix
// time complexity o(n+n)
// space complexity o(n)
string infix_to_postfix(string s){
    // arguments comes first
    string postfix_s = "";
    stack<char> st;
    st.push('#');
    for(int i=0; i<s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            postfix_s.push_back(s[i]);
        }else if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            // as this comes afterward we give priority to part inside () so first take it out
            while (st.top() != '#' && st.top() != '(') {
                postfix_s.push_back(st.top());
                st.pop();
            }
            st.pop();
        }else{
            while(priority(st.top()) > priority(s[i])){
                postfix_s.push_back(st.top());
                st.pop();
            } 
            st.push(s[i]);
        }
    }

    while(st.top()!='#'){
        postfix_s.push_back(st.top());
        st.pop();
    }
    st.pop();

    return postfix_s;
}

int get_value(int op1, int op2, char op){
    if(op == '^') return pow(op2, op1);
    if(op == '*') return op2 * op1;
    if(op == '/') return op2 / op1;
    if(op == '+') return op2 + op1;
    if(op == '-') return op2 - op1;
    return -1;
}

int postfixToInfix(string s){
    // it will always start with 2 character then it may be operator or char
    stack<int> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int new_value = get_value(op1, op2, s[i]);
            st.push(new_value);
        }
    }

    return st.top();
}

int main(){
    string infix_s = "a+b*(c^d-e)";
    string postfix_s = "3214^5-*+";
    cout<<infix_to_postfix(infix_s)<<endl;
    cout<<postfixToInfix(postfix_s)<<endl;
    return 0;
}