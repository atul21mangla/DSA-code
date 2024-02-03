#include <bits/stdc++.h>
using namespace std;
void subString(string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // for (int k = i; k <= j; k++)
            // {
            //     cout<<str[k];
                
            // }

            cout<<str.substr(i , j-i+1);
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    string str = "atul_coder";
    int n = str.size();
    subString(str, n);
}