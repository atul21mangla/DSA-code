#include<bits/stdc++.h>
using namespace std;

string PostfixToPrefix(string s){
    string answer;
    stack<string>st;

    int i=0;
    while(i<s.length()){
        char ch = s[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){ // operand
            st.push(string(1,ch));
        }

        else{  // operator
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string s = ch + t2 +  t1 ;
            st.push(s);
        }
        i++;
    }
    
    return st.top();
}

int main(){
    string s = "AB-DE+F*/";
    cout<<"Prefix Expression of given Postfix Expression is = "<<PostfixToPrefix(s)<<endl;
}