#include<bits/stdc++.h>
using namespace std;

bool checkPallindrome(string str,int start , int end){
    //! base case
    if(start>=end)return 1;
    if(str[start]!=str[end])return 0;
    return checkPallindrome(str,start+1,end-1);

}

int main(){
    string str = "madam";
    if(checkPallindrome(str,0,str.length()-1)){
        cout<<"Pallindrome"<<endl;
    }
    else cout<<"Not a Pallindrome"<<endl;
    return 0;
}