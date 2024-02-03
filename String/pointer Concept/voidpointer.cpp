#include <bits/stdc++.h>
using namespace std;
void increment(void *pvoid, int size)
{
    if (size == sizeof(int))
    {
        // pvoid points to an integer
        int *pint = (int *)pvoid;
        (*pint)++; // precedence(*) < precedence(++)
    }
    else if (size == sizeof(char))
    {
        // pvoid points to a character
        char *pchar = (char *)pvoid;
        (*pchar)++;
    }
}
int main()
{
    int x = 0;
    char y = 'a';

    increment(&x, sizeof(x));
    increment(&y, sizeof(y));

    cout << x << '\n'
         << y << endl;
         
    //! null pointers
    // null pointers are equal

	int* p = NULL;
	int* q = nullptr;
	int* r = 0;

	if(p == q and p == r) {
		cout << "they are equal";
	}

	//? you cannot derefernce a null pointers

	//* cout << *p << endl; // error

    return 0;
}