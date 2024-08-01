#include<iostream>
using namespace std;

void solve(string& str , int i , char c , string& ans){
    // Base case
    if(i==str.size()){
        return;
    }

    if(str[i]!=c){  // add in ans
        ans = ans+str[i];
        solve(str,i+1,c,ans); 
    }
    else{
        // skip
        solve(str,i+1,c,ans);
    }
}

int main(){
    string str = "vsanveaanveav";
    char c = 'v';
    string ans="";
    solve(str,0,c,ans);
    cout<<ans;
    return 0;
}