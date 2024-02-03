#include <bits/stdc++.h>
using namespace std;
int main()
{

    int x = 2;
    int *xptr; //? pointer declaration
    xptr = &x; //* pointer assignment

    cout << "value of x = " << x << endl;
    cout << "size of x = " << sizeof(x) << endl;
    cout << "address of x (&x) = " << &x << endl;
    cout << "value of xptr = " << xptr << endl;
    cout << "size of xptr = " << sizeof(xptr) << endl;
    cout << "-------------------------------------------------------" << endl;

    double y = 3;
    double *yptr; //? pointer declaration
    yptr = &y;    //* pointer assignment

    cout << "value of y = " << y << endl;
    cout << "size of y = " << sizeof(y) << endl;
    cout << "address of y (&y) = " << &y << endl;
    cout << "value of yptr = " << yptr << endl;
    cout << "size of yptr = " << sizeof(yptr) << endl;
    cout << "-------------------------------------------------------" << endl;

    char ch = 'A';
    char *chptr; //? pointer declaration
    chptr = &ch; //* pointer assignment

    cout << "value of ch = " << ch << endl;
    cout << "size of ch = " << sizeof(ch) << endl;
    cout << "address of ch (&ch) = " << &ch << endl;
    cout << "value of chptr = " << chptr << endl;
    cout << "size of chptr = " << sizeof(chptr) << endl;
    cout << "-------------------------------------------------------" << endl;
}