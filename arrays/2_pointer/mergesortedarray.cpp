#include<iostream>
using namespace std;

void printarr(int arr[10],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void mergeArray(int a[],int n,int b[],int m){
    int c[n+m];
    int i=0,j=0,k=0;;
    while(i<n && j<m){
        if(a[i] < b[j]){
            c[k] = a[i];
            k++,i++;                                // THREE POINTER APPROACH 
        }
        else{
            c[k] = b[j];
            k++,j++;
        }
    }
    while(i<n){
        c[k] = a[i];
        k++,i++;
    }
    while(j<m){
        c[k] = b[j];
        k++,j++;
    }
    cout<<"Merged array :"<<endl;
    // printing 
    printarr(c,n+m);
}

int main(){
    int a[10] , b[10];
    int n,m;
    cout<<"Enter size for both arrays :";
    cin>> n>>m;
    cout<<"Enter value in array 1 :";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter value in array 2 :";
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    mergeArray(a,n,b,m);             // WE ARE USING AN EXTRA ARRAY OF SIZE (n+m ) HERE 

}

