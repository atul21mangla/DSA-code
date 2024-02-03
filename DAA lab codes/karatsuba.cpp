#include <iostream>
#include <cmath>

using namespace std;

int karatsuba(int a, int b)
{
    string as = to_string(a);
    string bs = to_string(b);
    int a_len = as.length();
    int b_len = bs.length();
    int n = 0;
    int m = 0;

    if (a_len == 1 && b_len == 1)
    {
        return a * b;
    }
    else
    {
        n = max(a_len, b_len);
        m = ceil(n / 2.0);
        if (n % 2 != 0)
        {
            while (a_len != n + 1)
            {
                as = "0" + as;
                a_len = as.length();
            }
            while (b_len != n + 1)
            {
                bs = "0" + bs;
                b_len = bs.length();
            }
        }
        else
        {
            while (a_len != n)
            {
                as = "0" + as;
                a_len = as.length();
            }

            while (b_len != n)
            {
                bs = "0" + bs;
                b_len = bs.length();
            }
        }
        n=a_len;
        int a1 = stoi(as.substr(0, n / 2));
        int a2 = stoi(as.substr(n / 2));
        int b1 = stoi(bs.substr(0, n / 2));
        int b2 = stoi(bs.substr(n / 2));

        int A = karatsuba(a1, b1);
        int C = karatsuba(a1 + a2, b1 + b2);
        int B = karatsuba(a2, b2);
        int D = C - A - B;

        return (A * pow(10, 2 * m) + D * pow(10, m) + B);
    }
}

int main()
{
    cout<<"-------------------------------------------------------------------"<<endl;
    cout << "karatsuba output for odd case of (98712*2667) : ";
    cout << karatsuba(98712, 2667);
    cout<<endl<<"-------------------------------------------------------------------"<<endl;
    cout << "karatsuba output for even case of (224*129) : ";
    cout << karatsuba(224, 129);
    cout<<endl<<"-------------------------------------------------------------------"<<endl;
    return 0;
}
