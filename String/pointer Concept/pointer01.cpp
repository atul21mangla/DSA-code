#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 2;
    cout << "x = " << x << endl;
    cout << "address of x = " << &x << endl;
    cout << "size of (&x) = " << sizeof(&x) << "B" << endl;
    cout << "size of (x) = " << sizeof(x) << "B" << endl;

    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -" << endl;
    float y = 3;
    cout << "y = " << y << endl;
    cout << "address of y = " << &y << endl;
    cout << "size of (&y) = " << sizeof(&y) << "B" << endl;
    cout << "size of (y) = " << sizeof(y) << "B" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -" << endl;
    double z = 4;
    cout << "z = " << z << endl;
    cout << "address of z = " << &z << endl;
    cout << "size of (&z) = " << sizeof(&z) << "B" << endl;
    cout << "size of (z) = " << sizeof(z) << "B" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << endl;
    char ch = 'a';
    cout << "ch = " << ch << endl;
    cout << "address of ch = " << &ch << endl;
    cout << "size of (&ch) = " << sizeof(&ch) << "B" << endl;
    cout << "size of (ch) = " << sizeof(ch) << "B" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -";
}