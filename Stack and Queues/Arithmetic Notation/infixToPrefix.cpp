#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+' || c=='-')return 1;
    else return -1;
}

string infixToPrefix(string s){
    string answer;
    stack<char>st;
    reverse(s.begin(),s.end());
    int i=0;
    while(i<s.length()){
        char ch = s[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){       // operand
            answer += ch;
        }
        else if(ch==')')st.push(ch);
        else if(ch=='('){
            while(!st.empty() && st.top()!=')'){
                answer += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{                // operator
            while(!st.empty() && priority(ch)<priority(st.top())){
                answer += st.top();
                st.pop();
            }
            st.push(ch);
        }
        i++;
    }
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout<<"Prefix Expression of given Infix Expression is = "<<infixToPrefix(s)<<endl;
}