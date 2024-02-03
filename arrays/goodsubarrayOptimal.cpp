#include<iostream>
using namespace std;

void goodSubarray(int arr[] ,int n, int d){
    int freq[d] = {0};             //? bcuz freq array will only contain elements in range [0-d-1]
    int csum = 0;
    int total = 0;
    freq[0]= 1;
    for(int i=0;i<n;i++){
        csum+=arr[i];
        freq[csum%d]++;             //! if elements of array are negative then freq[((csum%d)+d)%d]
    }

    for(int i=0;i<d;i++){
        int x = freq[i];
        if(x>=2){
            total += (x*(x-1))/2;
        }
    }
    cout<<"number of good subarrays:"<<endl<<total;
}
int main(){
    int arr[] = {1,6,5,2,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 6;
    goodSubarray(arr,6,6);
}