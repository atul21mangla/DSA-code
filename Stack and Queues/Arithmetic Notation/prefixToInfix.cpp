#include<bits/stdc++.h>
using namespace std;

string PrefixToInfix(string s){
    string answer;
    stack<string>st;

    int i=s.length()-1;
    while(i>=0){
        char ch = s[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){ // operand
            st.push(string(1,ch));
        }
        else{  // operator
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string s = '(' + t1 + ch + t2 + ')';
            st.push(s);
        }
        i--;
    }
    
    return st.top();
}

int main(){
    string s = "*+PQ-MN";
    cout<<"Infix Expression of given Prefix Expression is = "<<PrefixToInfix(s)<<endl;
}