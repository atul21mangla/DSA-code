#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch = 'A';
    int *x = (int *)&ch;
    cout << "value of ch = " << ch << endl;
    cout << "&ch = " << &ch << endl;
    cout << "pointer x = " << x << endl;

    int i = 2;                            //? character pointer prints value stored in variable not address
    char *cp = (char *)&i;                 //* but we can get address of char variable by type casting its address in integer pointer
    cout << "value of i = " << i << endl;
    cout << "&i = " << &i << endl;
    cout << "pointer cp = " << cp << endl;

    //! pointer derefrencing
    int y = 4;
    int *yptr = &y; //? pointer initialisation
    cout << "value of yptr = " << *yptr << endl;
    cout << "address of y = " << yptr << endl;

    char *c = (char *)&y;
    cout << "value in c(pointer) = " << (int)*c << endl;
    cout << "address of y = " << c << endl;
}