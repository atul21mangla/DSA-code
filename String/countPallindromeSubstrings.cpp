#include<bits/stdc++.h>
using namespace std;

//! brute force approach ---> o(n^3)complexity

// bool isPallindrome(string str){
//     int i = 0;
//     int j = str.size()-1;
//     while(i<j){
//         if(str[i] != str[j]){
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }

// int countPallindromesubstrings(string str){
//     int count = 0;
//     for(int i=0;i<str.size();i++){
//         for(int j=i;j<str.size();j++){
//             string s = str.substr(i , j-i+1);
//             if(isPallindrome(s)){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int countPallindromesubstrings(string str){                //! optimal approach ----> O(N^2) complexity
    int count = 0;
    int n = str.size();

    // 1. counting odd length pallinfromic substrings
    for(int i=0;i<n;i++){
        int j = 0;
        while( i-j>=0 && i+j<=n && str[i-j]==str[i+j]){
            count++;
            j++;
        }
    }

    //2. counting even length pallinfromic substrings
    for(double i=0.5;i<n;i++){
        double j = 0.5;
        while( i-j>=0 && i+j<=n && str[i-j]==str[i+j]){
            count++;
            j++;
        }
    }
    return count;
}

int main(){
    string str = "abaaba";
    int n = str.size();
    cout<<countPallindromesubstrings(str);
}