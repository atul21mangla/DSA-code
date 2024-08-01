#include<iostream>
#include<vector>
using namespace std;

void parenthesis(int n , int x , int y , vector<char>& output , int idx){
    // Base Case
    if(idx== 2*n){
        for(int i=0;i<2*n;i++){
            cout<<output[i];
        }
        cout << endl;
        return;
    }

    // Recursive Case
    // 1. Add '('
    if(x<n){
        output[idx] = '(';
        parenthesis(n,x+1,y,output,idx+1);
    }
    // 2. Add ')'   //* y<x for balanced paranthesis as when x==y we can't use ')' 
    if(y<x){   //! y<n for all possible combinations 
        output[idx] = ')';
        parenthesis(n,x,y+1,output,idx+1);
    }
}

int main(){
    int n = 2;
    vector<char>output(2*n);
    parenthesis(n,0,0,output,0);
    return 0;
}