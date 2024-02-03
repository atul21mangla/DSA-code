#include<iostream>
using namespace std;

void insertionSort(int arr[] , int n){             //* we place 1st element of unsorted array to its correct position in sorted part
    for(int i=1;i<=n-1;i++){
        int key = arr[i];                          //? initially we assume 0th index element to be part of sorted array
        int j = i-1;  // tearsting from (i-1) to 0 
        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j];                      //! time compplexity ---> O(N^2) worst case  ----- and ----  O(N) best case 
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr, n);
    cout << "Array after sorting :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
