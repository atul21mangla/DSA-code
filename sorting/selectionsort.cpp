#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)       //* selects minimum elemenet from unsorted part of array 
{                                                 //* and puts it at correct position in sorted one.
    for (int i = 0; i < n - 1; i++)      //? no of passes are (n-1) 
    {                                       //? and in every ith pass we are iterating from (i+1) to (n-1) to check whether arr[i] is minimum or not
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }                                       //!  time complexity = O(N^2) in worst best and average case also
        }
        swap(arr[i], arr[min_index]);
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
    cout<<"Array before sorting :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }cout<<endl;
    selectionSort(arr, n);
    cout<<"Array after sorting :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}