#include <iostream>

using namespace std;

int main()
{

    int x = 10;                  //? only addition and subtraction is possible in pointer arithmetic
    int *xptr = &x;

    cout << "xptr = " << xptr << endl;
    cout << "*xptr = " << *xptr << endl;

    xptr++;

    cout << "xptr = " << xptr << endl;                         //* ptr = ptr + k  implies ptr + k*siszeof(type)
    cout << "*xptr = " << *xptr << endl;
    xptr++;
                                                
    cout << "xptr = " << xptr << endl;
    cout << "*xptr = " << *xptr << endl;

    double d = 21;
    double* dt = &d;

    cout<<"dt = "<<dt<<endl;
    cout<<"*dt = "<<*dt<<endl;

    dt++;
    cout<<"dt = "<<dt<<endl;
    cout<<"*dt = "<<*dt<<endl;

    return 0;
}