#include <bits/stdc++.h>
using namespace std;
bool goodString(string str)
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

int main()
{
    string str = "aeiou";
    if (goodString(str))
    {
        cout << "true";
    }
    else
        cout << "false";
}