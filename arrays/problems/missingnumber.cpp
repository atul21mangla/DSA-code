#include<iostream>
using namespace std;
int find_missing_number(int arr[] , int n){
    int sum = (n*(n+1))/2;
   int red_sum = 0;
   for (int i=0;i<n-1;i++){
       red_sum+=arr[i];
   }
   return sum-red_sum;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,10};
    int n = 10;
    cout<<find_missing_number(arr,n);
}
/*  
   ANOTHER OPTIMAL APPROACH 
   USING XOR -:

   int xor1=0 , xor2=0;
   for(int i=1;i<=n;i++){
        xor1 ^= i;
   }
    for(int i=0;i<n-1;i++){
        xor2 ^= arr[i];
   }
    calculate (xor1 ^ xor2)
   

*/