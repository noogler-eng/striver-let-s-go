// Pascal Triangle 
// input:           1
//                 1 1
//                1 2 1
//               1 3 3 1
//              .........

#include<iostream>
#include<math.h>
using namespace std;

// 1. elemnt at that place with row and col given
// ncr -> n! / r! * (n-r)! where n = r-1, r = c-1
// ncr -> n(n-1)(n-2)...(n-r) / r(r-1)(r-2)...1, start initiallt taking 1 in denomiator for easy dividation
int get_row_col_val(int n, int r){
    int res = 1, R = r-1, N = n-1;
    for(int i=0; i<R; i++){
        // do this seprately otherwise float will differ ans
        res *= (N-i);
        res /= (i+1);
    }
    return res;
}


// 2. print any Nth row of the pascal triangle
// brute force 
// time complexity o(n*n)
// space complexity o(1)
void print_any_row(int n){
    for(int i=1; i<=n; i++){
        cout<<get_row_col_val(n, i)<<" ";
    }
    cout<<endl;
}

// optmized approach
// time complexity o(n)
// space complexity o(1)
void print_any_row_o(int n){
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1; i<n; i++){
        // do this seprately otherwise float will differ ans
        ans *= (n-i);
        ans /= (i);
        cout<<ans<<" ";
    }
    cout<<endl;
}

// 3. print the entire triangle where n is given
// brute-force
// time complexity o(n*n*r)
// space complexity o(1)
void print_entire_triangle(int n){
    for(int j=1; j<=n; j++){
        for(int i=1; i<=j; i++){
            cout<<get_row_col_val(j, i)<<" ";
        }
        cout<<endl;
    }
}

// optmized approach
// time complexity o(n*n)
// space complexity o(1)
void print_entire_triangle_o(int n){
    for(int i=0; i<n; i++){
        int value = pow(11, i);
        while(value!=0){
            int lastDigit = value % 10;
            value = value / 10;
            cout<<lastDigit<<" ";
        }  
        cout<<endl;
    }
}

int main(){
    int n = 5, c = 3;
    cout<<get_row_col_val(n, c)<<endl;
    print_any_row(n);
    print_any_row_o(n);
    print_entire_triangle(n);
    print_entire_triangle_o(n);
    return 0;   
}