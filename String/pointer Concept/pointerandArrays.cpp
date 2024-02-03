#include<iostream>

using namespace std;

void arraySum(int* arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=*(arr+i);
    }
    cout<<"sum = "<<sum<<endl;
}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	// for(int i=0; i<n; i++) {

	// 	cout << arr[i] << " " << *(arr+i) << " " << &arr[i] << " " << (arr+i) << endl;

	// }

    arraySum(arr,n);

	return 0;
}