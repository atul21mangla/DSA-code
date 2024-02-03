#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)            //* loop for doing (n-1) passes
    {
        bool swapDone = false;
        for (int j = 0; j < n - i; j++)           //*  For ith pass we are doing (n-i) comparsions
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);         //! in Bubble Sort we push largest element to sorted part at last in each pass
                swapDone = true;                  //? by doing comparisions and swapping if necessary condition matches....
            }
        }
        if (!swapDone)
        {
            break;                     //! Time compplexity ---> O(N^2) worst case  ----- and ----  O(N) best case 
        }
    }
}

int main()
{
    int n;
    cout << "enter size of array :" << endl;
    cin >> n;
    int arr[50];
    cout << "enter input for array :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before sorting :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubbleSort(arr, n);
    cout << "Array after sorting :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
