#include<bits/stdc++.h>
using namespace std;

void printStr(string s){
    for(auto a:s)cout<<a;
    cout<<endl;
}

void myBubbleSort(string &s){
    int n = s.length();
    for(int i=1;i<=n-1;i++){
        bool swapDone = false;
        for(int j=0;j<n-i;j++){
            if(s[j]<s[j+1]){
                swap(s[j] , s[j+1]);
                swapDone = true;
            }
        }
        if(!swapDone)break;
    }
}

int main(){
    string s = "AXYCDHZXWXZSHX";
    printStr(s);
    string str ="";
    for(int i=0;i<s.length();i++){
        if(s[i] >= 'T')
        str += s[i];
    }
    cout<<"Before sorting the string :"<<endl;
    printStr(str);
    // sort(str.begin(),str.end());
    myBubbleSort(str);
    cout<<"After sorting the string :"<<endl;
    printStr(str);
}