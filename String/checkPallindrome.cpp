#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool isPallindrome(char* str , int n){
    int i = 0;
    int j = n-1;
    while(i<j){
        if(str[i] == str[j]){
            i++;
            j--;
            continue;
        }
        return false;
    }
    return true;
}
int main()
{
    char str[101] = "rotator";
    int n = strlen(str);
    // //? 1st approach
    // char rev_str[101];    //? o(n) space
    // strcpy(rev_str, str); //* o(n) time
    // int n = strlen(rev_str);
    // reverse(rev_str, rev_str + n);

    // int res = strcmp(str, rev_str);

    // if (res == 0)
    // {
    //     cout << "given string is pallindrome." << endl;
    // }
    // else
    // {
    //     cout << "not a pallindrome." << endl;
    // }

    //? Approach - 2
    if(isPallindrome(str,n)){                //! O(N) time only with O(1) constant space          
        cout<<"given string is pallindrome." << endl;
    }
    else
    cout << "not a pallindrome." << endl;
}