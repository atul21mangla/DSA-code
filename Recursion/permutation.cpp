#include<iostream>
using namespace std;

void permutation(string s , int i){
    int n = s.size();
    // Base Case
    if(i==n){
        cout << s << endl;
        return;
    }

    // Recursive Case
    
    for(int j=i;j<n;j++){
        swap(s[i],s[j]);
        permutation(s,i+1);
        // swap(s[i],s[j]);
    }
}

void permutationWithoutDuplicate(string s , int i){
    int n = s.size();
    // Base Case
    if(i==n){
        cout << s << endl;
        return;
    }

    // Recursive Case
    for(int j=i;j<n;j++){
        bool canSwap = true;
        for(int k=j+1;k<n;k++){
            if(s[k]==s[j]){
                canSwap = false;
                break;
            }
        }
        if(canSwap){
            swap(s[i],s[j]);
            permutationWithoutDuplicate(s,i+1);
            // swap(s[i],s[j]);
        }
    }
}

int main(){
    // string s = "abc";
    string s1 = "abac";
    permutationWithoutDuplicate(s1,0);
    // permutation(s,0);
    return 0;
}