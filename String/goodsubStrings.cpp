#include <bits/stdc++.h>
using namespace std;

bool IsgoodString(string str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
        {
            return false;
        }
    }
    return true;
}

//! BRUTE FORCE ---> O(N^3) complexity
// int goodsubString(string str)
// {
//     int maxlen = INT_MIN;
//     for (int i = 0; i < str.size(); i++)
//     {
//         for (int j = i; j < str.size(); j++)
//         {
//             string substring = str.substr(i, j - i + 1);
//             if (IsgoodString(substring))
//             {
//                 maxlen = max(maxlen , j-i+1);
//             }
//         }
//     }
//     return maxlen;
// }


//! OPTIMAL APPROACH --> O(N) Complexity
int goodsubString(string str){
    int count = 0;
    int maxlen = INT_MIN;
    int n = str.size();
    for(int i=0;i<n;i++){
        char ch = str[i];
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            count++;
            maxlen = max(maxlen,count);
        }
        else{
            count = 0;
        }
    }
    return maxlen;
}


int main()
{
    string str = "cbaeicaeio";
    cout << goodsubString(str) << endl;
}