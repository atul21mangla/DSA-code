#include<iostream>
using namespace std;

void generatePair(int arr[] , int n){
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
        cout<<endl;
    }
}

// int targetSum(int arr[],int n,int t){
//     int count=0;
//     for(int i=0;i<=n-2;i++){
//         for(int j=i+1;j<=n-1;j++){                                   BRUTE FORCE APPROACH
//             if(arr[i]+arr[j] == t){
//                 count++;                                           TIME COMPLEXITY  << O(N^2)  >>   SPACE COMPLEXITY <<  O(1) >>
//                 cout<<"("<< arr[i]<<","<<arr[j]<<")"<<endl;
//             }
//         }
//     }
//     return count;

// }

int targetSum(int arr[],int n,int t){
    int count = 0;
    int i= 0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j] == t){
            count++;
            cout<<"("<< arr[i]<<","<<arr[j]<<")"<<endl;
            i++ , j--;                                                // OPTIMAL APPROACH
        }                                                             // O(N) 
        else if(arr[i]+arr[j] > t){
            j--;
        }
        else i++;
    }
    return count;
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int t = 0;
    //generatePair(arr,n);
    cout<<targetSum(arr,n,t)<<" combinations possible";
}
