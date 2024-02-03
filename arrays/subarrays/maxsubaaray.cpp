#include<iostream>
#include<climits>
using namespace std;

// int maxSubarray(int arr[] , int n){
//     int maxi = INT_MIN;
//     for(int i=0;i<n;i++){

//         for(int j=i;j<n;j++){
//                                                   BRUTE FORCE APPROACH 
//             int sum = 0;
//             for(int k=i;k<=j;k++){              TIME COMPLEXITY O(N^3)
//                 sum+= arr[k];
//                 maxi = max(maxi,sum);
//             }
//         }
//     }
//     return maxi;
// }

// int maxSubarray(int arr[] , int n){
//     int maxi = INT_MIN;
//     for(int i=0;i<n;i++){                         // BETTER APPROACH
//         int sum = 0;
//         for(int j=i;j<n;j++){                     //TIME COMPLEXITY O(N^2)
//             sum+= arr[j];
//             maxi = max(maxi,sum);
//         }
//     }
//     return maxi;
// }

int maxSubarray(int arr[] , int n){
    int maxi = INT_MIN;
    int sum = arr[0];
    for(int i=1;i<n;i++){                         // OPTIMAL APPROACH
        sum = max(sum + arr[i] , arr[i]);         //TIME COMPLEXITY O(N)
        maxi = max(sum , maxi);
    }
    return maxi;
}

int main(){
    int arr[8] = {-2,-5,6,-2,-3,1,5,-6}; 
    cout<<"maximum subarray sum is :"<<endl;
    cout<<maxSubarray(arr , 8);
}