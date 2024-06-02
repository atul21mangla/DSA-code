#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printLCS(string x, vector<vector<int>> b, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    else if (b[i][j] == 1)
    {
        printLCS(x, b, i - 1, j - 1);
        cout << x[i - 1];  
    }
    else if (b[i][j] == 2)
    {
        printLCS(x, b, i - 1, j);
    }
    else if (b[i][j] == 3)
    {
        printLCS(x, b, i, j - 1);
    }
    else
    {
        return;
    }
}

void LCS(string x, string y)
{
    int m, n;
    m = x.length();
    n = y.length();
    vector<vector<int>> c(m + 1, vector<int>(n + 1));
    vector<vector<int>> b(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if ((x[i - 1] != y[j - 1]) && (c[i - 1][j] >= c[i][j - 1]))
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }

    cout << "Length of longest subsequence = " << c[m][n] << endl;

    cout << "Subsequence = ";
    printLCS(x, b, m, n);
    cout << "\n";
    cout << "\n";

    cout << "c-Matrix : " <<endl;
    cout << "0 0 ";
    for (int i = 0; i < n; i++)
    {
        cout << y[i] << " ";
    }

    cout << "\n0 ";
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
        cout << x[i] << " ";
    }
    cout << "\n";
    cout << "b-Matrix : " <<endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    string x, y;
    // x = "acbcf";
    // y = "abcdaf";
    cout << "Enter String 1 : ";
    getline(cin, x);
    cout << "Enter String 2 : ";
    getline(cin, y);
    cout << "\n";
    LCS(x, y);
    return 0;
}